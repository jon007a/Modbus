#include <QQuickWidget>
#include <QVBoxLayout>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connectionsettings.h"
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
#include <QtCharts/QLineSeries>
#include <QLabel>
#include <QPixmap>
#include "statistictwo.h"
#include <QDesktopServices>


Statistic *statistic;




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , modbusDevice(nullptr) // инициализация клиента как nullptr
    , userSelected(false)
{
    setWindowIcon(QIcon("C:/Qt/Raboti/vfd/pictures/icon1.png"));


    ui->setupUi(this);
    setupStatusBar();

    disableControls();


    statistic = new Statistic(this);
    //connect(this, &MainWindow::motorSpeedUpdated, statistic, &Statistic::receiveMotorSpeed);
    //Statistic *statisticWindow = new Statistic();
    //statisticWindow->setupConnections(this);


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
    timer->start(500); // Запрос каждые 1000 мс (1 секунда)


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
        statusBar()->showMessage("Database connection failed", 2000);
    } else {
        qDebug() << "Connected to the database successfully!";
        statusBar()->showMessage("Connected to the database successfully", 2000);
    }
}



void MainWindow::insertFanSpeedToDatabase(int fanSpeed) {
    QSqlQuery query;
    query.prepare("INSERT INTO FanSpeedData (speed, timestamp) VALUES (:speed, :timestamp)");
    query.bindValue(":speed", fanSpeed);
    query.bindValue(":timestamp", QDateTime::currentDateTime());

    if (!query.exec()) {
        qDebug() << "Ошибка при вставке данных в базу:" << query.lastError().text();
        statusBar()->showMessage("Ошибка при вставке данных в базу", 5000);
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
    if (!userSelected) {
        QMessageBox::warning(this, "Warning", "Vyberite pol'zovatelya pered podklyucheniem");
        return;
    }

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
            onSlaveConnected();

            statusIndicator->setPixmap(QPixmap("C:/Qt/Raboti/vfd/icon/icon1.jpg")); // Зеленая иконка
            statusBar()->showMessage("Connected to RTU device", 2000);
        } else {
            qDebug() << "Failed to connect to RTU device";
            statusBar()->showMessage("Failed to connect to RTU device", 5000);
        }

        modbusDevice = rtuClient;

    } else if (connectionType == "TCP") {
        QModbusTcpClient *tcpClient = new QModbusTcpClient(this);
        tcpClient->setConnectionParameter(QModbusDevice::NetworkAddressParameter, ipAddress);
        tcpClient->setConnectionParameter(QModbusDevice::NetworkPortParameter, port);

        // Устанавливаем таймаут ожидания в миллисекундах (например, 5000 мс = 5 секунд)
        tcpClient->setTimeout(10000);

        if (!tcpClient->connectDevice()) {
            qDebug() << "Failed to connect to TCP device.";
            statusBar()->showMessage("Failed to connect to TCP device", 5000);
        } else {
            qDebug() << "Successfully connected to TCP device.";
            statusIndicator->setPixmap(QPixmap("C:/Qt/Raboti/vfd/icon/icon1.jpg")); // Зеленая иконка
            statusBar()->showMessage("Successfully connected to TCP device", 2000);
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
    if (!reply) return;

    if (reply->error() == QModbusDevice::NoError) {
        packetCount++;
        const QModbusDataUnit unit = reply->result();

        int motorSpeed = unit.value(0);  // Получаем значение скорости мотора

        // Получаем значение второго блока регистра (для progressBar)
        int progressValue = unit.value(1);  // Второй регистр

        // Получаем значение третьего блока регистра (для progressBar)
        int progressValue2 = unit.value(2);  // третий регистр


        QQuickItem *qmlObject = qmlWidget->rootObject();
        if (qmlObject) {
            qmlObject->setProperty("dialValue", motorSpeed);  // Обновляем значение на виджете
            qDebug() << "Motor speed updated to:" << motorSpeed;  // Логируем обновленное значение
        } else {
            qDebug() << "No root object found!";
        }


        // Обновляем прогресс бары
        if (ui->progressBar1) {
            ui->progressBar1->setValue(progressValue);
            qDebug() << "ProgressBar1 updated to:" << progressValue;
        }

        if (ui->progressBar22) {
            ui->progressBar22->setValue(progressValue2);
            qDebug() << "ProgressBar2 updated to:" << progressValue2;
        }

        // Сохраняем данные только если пользователь выбран
        if (userSelected && !currentUser.isEmpty()) {
            insertDataToUserTable(currentUser, motorSpeed, progressValue, progressValue2);
            qDebug() << "Saving data for user:" << currentUser;
        }





        emit motorSpeedUpdated(motorSpeed);
        emit progressbars(progressValue);
        emit progressbars2(progressValue2);

        // Обновляем информацию о подключении
        if (modbusDevice) {
            QString type = (dynamic_cast<QModbusRtuSerialClient*>(modbusDevice)) ? "RTU" : "TCP";
            QString address = type == "RTU" ?
                                  modbusDevice->connectionParameter(QModbusDevice::SerialPortNameParameter).toString() :
                                  modbusDevice->connectionParameter(QModbusDevice::NetworkAddressParameter).toString();
            updateConnectionInfo(type, address, packetCount, errorCount);
        }

    } else {
        errorCount++;
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
        connect(statisticsWindow, &Statistic::userSelected,
                this, &MainWindow::setCurrentUser);
    }
    statisticsWindow->show();
}



void MainWindow::setupStatusBar()
{
    // Создаем постоянные виджеты для статусбара
    QLabel *versionLabel = new QLabel("Версия 1.0.0", this);
    statusIndicator = new QLabel(this);

    // Создаем лейбл для информации о подключении
    QLabel *connectionInfoLabel = new QLabel(this);
    connectionInfoLabel->setFrameStyle(QFrame::NoFrame); // Убираем рамку
    connectionInfoLabel->setMinimumWidth(300);
    connectionInfoLabel->setText("TCP/RTU     Packets : 0    Erros : 0");



    // Создаем пустой растягивающийся виджет для отступа слева
    QWidget *spacer = new QWidget(this);
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    // Устанавливаем иконку статуса
    QPixmap redIcon("C:/Qt/Raboti/vfd/icon/icon2.jpg");
    statusIndicator->setPixmap(redIcon);

    // Добавляем все элементы в статусбар в нужном порядке
    statusBar()->addWidget(spacer);

    // Добавляем отступы для элементов через стиль
    connectionInfoLabel->setStyleSheet("QLabel { margin-right: 10px; }");
    versionLabel->setStyleSheet("QLabel { margin-right: 10px; }");

    statusBar()->addPermanentWidget(connectionInfoLabel);
    statusBar()->addPermanentWidget(versionLabel);
    statusBar()->addPermanentWidget(statusIndicator);

    // Убираем границу самого статусбара
    statusBar()->setStyleSheet("QStatusBar::item { border: none; }");

    // Сохраняем указатель на лейбл для последующего обновления
    connectionLabel = connectionInfoLabel;
}

void MainWindow::onSlaveConnected() {
    emit slaveConnected(); // Уведомляем о подключении
    qDebug() << "Устройство подключено.";
    //statistic->Chart();
}

void MainWindow::onSlaveDisconnected() {
    emit slaveDisconnected(); // Уведомляем об отключении
    qDebug() << "Устройство отключено.";
}


void MainWindow::on_action_2_triggered()
{

    if (!statisticTwoWindow) {
        statisticTwoWindow = new statistictwo(this); // Создаём объект типа StatisticTwo

        // Соединяем сигнал обновления скорости с слотом в statistictwo
        connect(this, &MainWindow::motorSpeedUpdated, statisticTwoWindow, &statistictwo::receiveMotorSpeed);
        connect(this, &MainWindow::progressbars, statisticTwoWindow, &statistictwo::receiveProgressbars);
        connect(this, &MainWindow::progressbars2, statisticTwoWindow, &statistictwo::receiveProgressbars2);
    }
    statisticTwoWindow->show();
    statisticTwoWindow->raise();    // Поднимаем окно на передний план
    statisticTwoWindow->activateWindow(); // Делаем активным

}

void MainWindow::disableControls()
{
    // Отключаем меню подключения и другие элементы управления
    ui->menuConnection_type->setEnabled(false);
    ui->qmlWidget->setEnabled(false);
    ui->progressBar1->setEnabled(false);
    ui->progressBar22->setEnabled(false);

    // Показываем сообщение пользователю
    statusBar()->showMessage("Выберите пользователя перед подключением к устройству", 5000);
}

void MainWindow::enableControls()
{
    // Включаем все элементы управления
    ui->menuConnection_type->setEnabled(true);
    ui->qmlWidget->setEnabled(true);
    ui->progressBar1->setEnabled(true);
    ui->progressBar22->setEnabled(true);

    statusBar()->showMessage("Пользователь выбран: " + currentUser, 5000);
}

void MainWindow::setCurrentUser(const QString &username)
{
    currentUser = username;
    userSelected = true;

    // Создаем таблицу для пользователя
    if (createUserTable(username)) {
        enableControls();
    } else {
        QMessageBox::critical(this, "Error", "Ne udalos' sozdat' tablicu dlya pol'zovatelya");
        userSelected = false;
    }
}

bool MainWindow::createUserTable(const QString &username)
{
    if (username.isEmpty()) {
        qDebug() << "Cannot create table for empty username";
        return false;
    }

    QSqlQuery query;
    QString tableName = "motor_data_" + username.toLower();

    // Используем двойные кавычки для имени таблицы
    QString createTableQuery = QString(
                                   "CREATE TABLE IF NOT EXISTS \"%1\" ("
                                   "id SERIAL PRIMARY KEY,"
                                   "speed INTEGER,"
                                   "progress1 INTEGER,"
                                   "progress2 INTEGER,"
                                   "timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP"
                                   ")").arg(tableName);

    if (!query.exec(createTableQuery)) {
        qDebug() << "Error creating table for user" << username
                 << ":" << query.lastError().text()
                 << "\nQuery was:" << createTableQuery;
        return false;
    }

    qDebug() << "Successfully created table for user" << username;
    return true;
}

void MainWindow::insertDataToUserTable(const QString &username, int motorSpeed, int progress1, int progress2)
{
    if (!userSelected || username.isEmpty()) {
        qDebug() << "Skipping data insert - no user selected or empty username";
        return;
    }

    QString tableName = "motor_data_" + username.toLower();
    QSqlQuery query;

    // Используем подготовленный запрос с правильным экранированием имени таблицы
    QString queryStr = QString("INSERT INTO \"%1\" (speed, progress1, progress2) VALUES ($1, $2, $3)").arg(tableName);
    query.prepare(queryStr);

    query.bindValue(0, motorSpeed);
    query.bindValue(1, progress1);
    query.bindValue(2, progress2);

    if (!query.exec()) {
        qDebug() << "Database error when inserting data for user" << username
                 << ":" << query.lastError().text()
                 << "\nQuery was:" << query.lastQuery();
    } else {
        qDebug() << "Successfully inserted data for user" << username
                 << ": speed=" << motorSpeed
                 << ", progress1=" << progress1
                 << ", progress2=" << progress2;
    }
}

void MainWindow::on_actionOpenManual_triggered()
{
    QString manualPath = "C:/Qt/Raboti/vfd/ModbusManual/index.html";
    QFileInfo fileInfo(manualPath);

    qDebug() << "Trying to open manual at:" << manualPath;  // Добавляем для отладки

    if (fileInfo.exists()) {
        QUrl url = QUrl::fromLocalFile(fileInfo.absoluteFilePath());
        if (!QDesktopServices::openUrl(url)) {
            QMessageBox::warning(this, "Error",
                                 "Ne udalos' otkryt' manual. Prover'te ustanovlen li brauzer po umolchaniyu.");
        }
    } else {
        qDebug() << "Manual path not found:" << manualPath;
        QMessageBox::warning(this, "Error",
                             "Manual ne nayden. Put': " + manualPath);
    }
}

void MainWindow::updateConnectionInfo(const QString &type, const QString &address, int packets, int errors)
{
    if (connectionLabel) {
        QString info = QString("%1 : %2    Packets : %3    Erros : %4")
        .arg(type)
            .arg(address)
            .arg(packets)
            .arg(errors);
        connectionLabel->setText(info);
    }
}
