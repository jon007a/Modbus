#include <QQuickWidget>
#include <QVBoxLayout>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ConnectionSettings.h"
#include <QUrl>
#include <QModbusRtuSerialMaster>
#include <QModbusTcpClient>
#include <QDebug>
#include <QQuickItem>
#include <QtGlobal>
#include <QTimer>
#include <statistic.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , modbusDevice(nullptr) // инициализация клиента как nullptr
{
    ui->setupUi(this);

    // Настраиваем подключение к базе данных
    setupDatabaseConnection();

    // Создаем QQuickWidget
    qmlWidget = new QQuickWidget(this);
    qDebug() << "Loading QML...";
    qmlWidget->setSource(QUrl::fromLocalFile("C:/Qt/Raboti/vfd/dialcontrol/dialcontrol.qml")); // Абсолютный путь

    // Проверяем статус после загрузки
    if (qmlWidget->status() == QQuickWidget::Error) {
        qDebug() << "Error loading QML:" << qmlWidget->errors();
    } else {
        qDebug() << "QML loaded.";
    }

    // Извлекаем корневой объект QML
    QQuickItem *rootObject = qmlWidget->rootObject();
    if (rootObject) {
        qDebug() << "Root object found.";

        // Подключаем сигнал изменения слайдера
        connect(rootObject, SIGNAL(sliderValueChanged(int)), this, SLOT(onSliderValueChanged(int)));  // Подключаем сигнал изменения слайдера
        connect(rootObject, SIGNAL(sendSpeedChange(qreal)), this, SLOT(sendSpeedChange(qreal))); // Подключаем сигнал изменения скорости
    } else {
        qDebug() << "No root object found!";
    }

    // Добавляем QQuickWidget в основной layout
    qDebug() << "Adding QQuickWidget to layout...";
    if (ui->qmlWidget->layout() == nullptr) {
        ui->qmlWidget->setLayout(new QVBoxLayout()); // Устанавливаем макет, если он не установлен
    }
    ui->qmlWidget->layout()->addWidget(qmlWidget); // Добавляем QQuickWidget в макет
    qDebug() << "Widget added to layout.";



    // Создаем таймер для периодического обновления данных с Modbus
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::requestDataFromModbus);
    timer->start(1000); // Запрос каждые 1000 мс (1 секунда)
}

void MainWindow::setupDatabaseConnection()
{
    db = QSqlDatabase::addDatabase("QPSQL"); // Убедитесь, что драйвер PostgreSQL подключен
    db.setHostName("localhost");
    db.setDatabaseName("Statisticbase"); // Замените на имя вашей БД
    db.setUserName("postgres"); // Замените на ваше имя пользователя
    db.setPassword("1234"); // Замените на ваш пароль
    db.setPort(5432);

    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
    } else {
        qDebug() << "Connected to the database successfully!";
    }
}



void MainWindow::insertFanSpeedToDatabase(int fanSpeed) {
    QSqlQuery query;
    query.prepare("INSERT INTO FanSpeedData (speed, timestamp) VALUES (:speed, :timestamp)");
    query.bindValue(":speed", fanSpeed);
    query.bindValue(":timestamp", QDateTime::currentDateTime());

    if (!query.exec()) {
        qDebug() << "Ошибка при вставке данных в базу:" << query.lastError().text();
    } else {
        qDebug() << "Скорость вращения успешно занесена в базу данных.";
    }
}

void MainWindow::requestDataFromModbus()
{
    if (modbusDevice) {
        QModbusDataUnit readRequest(QModbusDataUnit::HoldingRegisters, 0, 3);  // Чтение регистра с адреса 0
        if (auto *reply = modbusDevice->sendReadRequest(readRequest, 1)) {  // Slave ID = 1
            connect(reply, &QModbusReply::finished, this, &MainWindow::onModbusReadReady);
        }
    }
}


void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    if (qmlWidget) {
        qmlWidget->setMinimumSize(size()); // Убедитесь, что qmlWidget адаптируется к размеру
    }
}

MainWindow::~MainWindow()
{
    if (modbusDevice)
        modbusDevice->disconnectDevice();
    delete ui;
}

// Слот для открытия окна настроек
void MainWindow::on_actionrtu_triggered()
{
    // Создаем объект окна настроек подключения
    ConnectionSettings settingsDialog(this);

    // Соединяем сигнал с настройками с соответствующим слотом в главном окне
    connect(&settingsDialog, &ConnectionSettings::settingsApplied, this, &MainWindow::applySettings);

    // Открываем окно в модальном режиме
    settingsDialog.exec();
}



// Применение настроек подключения
void MainWindow::applySettings(QString connectionType, int comPort, int baudRate, int dataBits, int stopBits, int parity, QString ipAddress, int port)
{
    if (modbusDevice) {
        modbusDevice->disconnectDevice();
        delete modbusDevice;
        modbusDevice = nullptr;
    }

    if (connectionType == "RTU") {
        QModbusRtuSerialClient *rtuClient = new QModbusRtuSerialClient(this);
        rtuClient->setConnectionParameter(QModbusDevice::SerialPortNameParameter, QString("COM%1").arg(comPort));
        rtuClient->setConnectionParameter(QModbusDevice::SerialBaudRateParameter, baudRate);
        rtuClient->setConnectionParameter(QModbusDevice::SerialDataBitsParameter, dataBits);
        rtuClient->setConnectionParameter(QModbusDevice::SerialStopBitsParameter, stopBits);
        rtuClient->setConnectionParameter(QModbusDevice::SerialParityParameter, parity);
        rtuClient->setTimeout(1000);
        rtuClient->setNumberOfRetries(3);

        if (rtuClient->connectDevice()) {
            qDebug() << "Connected to RTU device";
        } else {
            qDebug() << "Failed to connect to RTU device";
        }

        modbusDevice = rtuClient;

    } else if (connectionType == "TCP") {
        QModbusTcpClient *tcpClient = new QModbusTcpClient(this);
        tcpClient->setConnectionParameter(QModbusDevice::NetworkAddressParameter, ipAddress);
        tcpClient->setConnectionParameter(QModbusDevice::NetworkPortParameter, port);

        if (!tcpClient->connectDevice()) {
            qDebug() << "Failed to connect to TCP device.";
        } else {
            qDebug() << "Successfully connected to TCP device.";
        }

        modbusDevice = tcpClient;  // Сохраняем указатель на TCP-клиент
    }

    // После подключения можно начать считывать данные
    if (modbusDevice) {
        QModbusDataUnit readRequest(QModbusDataUnit::HoldingRegisters, 0, 3);  // Чтение регистра с адреса 0
        if (auto *reply = modbusDevice->sendReadRequest(readRequest, 1)) {  // Slave ID = 1
            connect(reply, &QModbusReply::finished, this, &MainWindow::onModbusReadReady);
        }
    }
}

// Слот для обработки данных с Modbus
void MainWindow::onModbusReadReady()
{
    auto *reply = qobject_cast<QModbusReply *>(sender());
    if (!reply)
        return;

    // Логируем статус ответа
    qDebug() << "Received Modbus reply:";

    if (reply->error() == QModbusDevice::NoError) {
        const QModbusDataUnit unit = reply->result();
        int motorSpeed = unit.value(0);  // Получаем значение скорости мотора

        // Получаем значение второго регистра (для progressBar)
        int progressValue = unit.value(1);  // Второй регистр

        // Получаем значение второго регистра (для progressBar)
        int progressValue2 = unit.value(2);  // Второй регистр


        QQuickItem *qmlObject = qmlWidget->rootObject();
        if (qmlObject) {
            qmlObject->setProperty("dialValue", motorSpeed);  // Обновляем значение на виджете
            qDebug() << "Motor speed updated to:" << motorSpeed;  // Логируем обновленное значение
        } else {
            qDebug() << "No root object found!";
        }


        //обработка второго регистра
        if (ui->progressBar1) {
            ui->progressBar1->setValue(progressValue);
            qDebug() << "ProgressBar1 updated to:" << progressValue;
        }
        //обработка третьего регистра
        if (ui->progressBar22) {
            ui->progressBar22->setValue(progressValue2);
            qDebug() << "ProgressBar2 updated to:" << progressValue2;
        }

        // Сохранение данных в базу данных
        QSqlQuery query;
        query.prepare("INSERT INTO motor_data (speed, progress1, progress2) VALUES (?, ?, ?)");
        query.addBindValue(motorSpeed);
        query.addBindValue(progressValue);
        query.addBindValue(progressValue2);

        if (!query.exec()) {
            qDebug() << "Database error:" << query.lastError().text();  // Логируем ошибку, если она произошла
        } else {
            qDebug() << "Data saved to database: Speed =" << motorSpeed
                     << ", Progress1 =" << progressValue
                     << ", Progress2 =" << progressValue2;
        }

    } else {
        qDebug() << "Modbus read error:" << reply->errorString();  // Логируем ошибку, если она произошла
    }

    reply->deleteLater();
}

// Слот для изменения значения слайдера
void MainWindow::onSliderValueChanged(int newValue)
{
    if (!modbusDevice) return; // Убедитесь, что устройство подключено

    // Создаем запрос на запись нового значения в регистр
    QModbusDataUnit writeRequest(QModbusDataUnit::HoldingRegisters, 0, 1); // Указываем адрес регистра и количество регистров
    writeRequest.setValue(0, newValue); // Устанавливаем новое значение

    // Отправляем запрос
    if (auto *reply = modbusDevice->sendWriteRequest(writeRequest, 1)) { // Slave ID = 1
        connect(reply, &QModbusReply::finished, this, [reply]() {
            if (reply->error() == QModbusDevice::NoError) {
                qDebug() << "Successfully wrote new value to register.";
            } else {
                qDebug() << "Failed to write value:" << reply->errorString();
            }
            reply->deleteLater();
        });
    } else {
        qDebug() << "Write request failed.";
    }
}
void MainWindow::sendSpeedChange(qreal speed)
{
    if (!modbusDevice) return; // Убедитесь, что устройство подключено

    // Создаем запрос на запись нового значения в регистр
    QModbusDataUnit writeRequest(QModbusDataUnit::HoldingRegisters, 0, 1); // Указываем адрес регистра и количество регистров
    writeRequest.setValue(0, static_cast<quint16>(speed)); // Устанавливаем новое значение (возможно, нужно привести к подходящему типу)

    // Отправляем запрос
    if (auto *reply = modbusDevice->sendWriteRequest(writeRequest, 1)) { // Slave ID = 1
        connect(reply, &QModbusReply::finished, this, [reply]() {
            if (reply->error() == QModbusDevice::NoError) {
                qDebug() << "Successfully wrote new speed value to register.";
            } else {
                qDebug() << "Failed to write speed value:" << reply->errorString();
            }
            reply->deleteLater();
        });
    } else {
        qDebug() << "Write request failed.";
    }

}

void MainWindow::on_action_triggered()
{
    if (!statisticsWindow) {
        statisticsWindow = new Statistic(this);
    }
    statisticsWindow->show();
}
