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
#include "registration.h"
#include "errorwindow.h"
#include <QFileDialog> //wordotchet
#include <QDateTime>


Statistic *statistic;




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , modbusDevice(nullptr) // инициализация клиента как nullptr
    , userSelected(false)
    , isAdminUser(false)

{


    // Устанавливаем темную тему
    setStyleSheet(R"(
    QMainWindow {
        background-color: #1E1E1E;
    }
    QWidget {
        background-color: #1E1E1E;
        color: #D4D4D4;
    }
    QMenuBar {
        background-color: #1E1E1E;
        color: #D4D4D4;
        border-bottom: 1px solid #2D2D2D;
    }
    QMenuBar::item:selected {
        background-color: #2D2D2D;
    }
    QMenu {
        background-color: #1E1E1E;
        color: #D4D4D4;
        border: 1px solid #2D2D2D;
    }
    QMenu::item:selected {
        background-color: #2D2D2D;
    }


)");

    setWindowIcon(QIcon("C:/Qt/Raboti/vfd/pictures/icon1.png"));


    ui->setupUi(this);
    setupStatusBar();


    disableControls();

    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startDrive);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::stopDrive);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::resetDrive);
    connect(ui->actionExportReport, &QAction::triggered, this, &MainWindow::on_actionExportReport_triggered);
    // Соединяем кнопку установки скорости с соответствующим слотом
    connect(ui->setSpeedButton, &QPushButton::clicked, this, &MainWindow::onManualSpeedEntered);

    // Также можно добавить обработку нажатия Enter в поле ввода
    connect(ui->speedInput, &QLineEdit::returnPressed, this, &MainWindow::onManualSpeedEntered);



    statistic = new Statistic(this);





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
        connect(rootObject, SIGNAL(sliderValueChanged(int)),
                this, SLOT(onSliderValueChanged(int)));

        connect(rootObject, SIGNAL(sendSpeedChange(qreal)),
                this, SLOT(sendSpeedChange(qreal)));

        // Добавим отладочную информацию
        qDebug() << "Signals connected successfully";
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
    QString connectionName = generateConnectionName();
    db = QSqlDatabase::addDatabase("QPSQL", connectionName); // Убедитесь, что драйвер PostgreSQL подключен
    db.setHostName("localhost");
    db.setDatabaseName("statisticbase"); // Замените на имя вашей БД
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
    QSqlQuery query(db);
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
    if (!modbusDevice || !userSelected) return;

    // Читаем 6 регистров начиная с 0
    QModbusDataUnit readRequest(QModbusDataUnit::HoldingRegisters, 0, 40000);

    if (auto *reply = modbusDevice->sendReadRequest(readRequest, 1)) {
        connect(reply, &QModbusReply::finished, this, &MainWindow::onModbusReadReady);
    } else {
        errorPackets++;

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

            QPixmap greenIcon("C:/Qt/Raboti/vfd/icon/icon11.svg");
            statusIndicator->setPixmap(QPixmap("C:/Qt/Raboti/vfd/icon/icon11.svg")); // Зеленая иконка
            statusIndicator->setPixmap(greenIcon.scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation));
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

            QPixmap greenIcon("C:/Qt/Raboti/vfd/icon/icon11.svg");
            statusIndicator->setPixmap(greenIcon);
            statusIndicator->setPixmap(greenIcon.scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            statusBar()->showMessage("Successfully connected to TCP device", 2000);
        }

        modbusDevice = tcpClient;  // Сохраняем указатель на TCP-клиент
    }

    // После подключения можно начать считывать данные
    if (modbusDevice) {

        QModbusDataUnit readRequest(QModbusDataUnit::HoldingRegisters, 0, 6);  // Чтение регистра с адреса 0
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
        const QModbusDataUnit unit = reply->result();

        // Получаем значения из всех регистров
        quint16 controlWord = unit.value(REG_CONTROL);  // Регистр 0
        quint16 statusWord = unit.value(REG_STATUS);    // Регистр 1
        quint16 speedRaw = unit.value(REG_SPEED);       // Регистр 2
        quint16 currentRaw = unit.value(REG_CURRENT);   // Регистр 3
        quint16 voltageRaw = unit.value(REG_VOLTAGE);   // Регистр 4
        quint16 tempRaw = unit.value(REG_TEMP);         // Регистр 5

        // Обновляем статус привода
        updateDriveStatus(statusWord);

        // Преобразуем в реальные значения
        double speed = (speedRaw / MAX_SPEED_VALUE) * 3000.0;
        double current = currentRaw * CURRENT_SCALE;
        double voltage = voltageRaw;
        double temperature = tempRaw;

        // Обновляем UI
        if (ui->progressBar1) {
            ui->progressBar1->setValue(current);
        }
        if (ui->progressBar22) {
            ui->progressBar22->setValue(voltage);
        }
        if (ui->progressBar4) {
            ui->progressBar4->setValue(temperature);
        }

        // Обновляем QML интерфейс
        if (qmlWidget) {
            QQuickItem *rootObject = qmlWidget->rootObject();
            if (rootObject) {
                rootObject->setProperty("dialValue", speed);
            }
        }

        // Сохраняем данные в БД
        insertDataToUserTable(currentUser,
                              controlWord,
                              statusWord,
                              static_cast<int>(speed),
                              static_cast<int>(current),
                              static_cast<int>(voltage),
                              static_cast<int>(temperature));

        // Отправляем сигналы для графиков
        emit motorSpeedUpdated(speed);
        emit progressbars(current);
        emit progressbars2(voltage);
        emit progressbars4(temperature);

        successPackets++;
    } else {
        errorPackets++;
        qDebug() << "Modbus error:" << reply->errorString();
    }

    if (modbusDevice) {
        QString type = (dynamic_cast<QModbusRtuSerialClient*>(modbusDevice)) ? "RTU" : "TCP";
        QString address = type == "RTU" ?
                              modbusDevice->connectionParameter(QModbusDevice::SerialPortNameParameter).toString() :
                              modbusDevice->connectionParameter(QModbusDevice::NetworkAddressParameter).toString();
        updateConnectionInfo(type, address, successPackets, errorPackets);
    }

    reply->deleteLater();
}


// Слот для изменения значения слайдера
void MainWindow::onSliderValueChanged(int newValue)
{
    qDebug() << "Slider value changed to:" << newValue;
    qDebug() << "Device status:"
             << "modbusDevice:" << (modbusDevice != nullptr)
             << "userSelected:" << userSelected
             << "isRunning:" << isRunning;

    if (!modbusDevice) {
        qDebug() << "Cannot change speed: modbusDevice is null";
        return;
    }
    if (!userSelected) {
        qDebug() << "Cannot change speed: user not selected";
        return;
    }
    if (!isRunning) {
        qDebug() << "Cannot change speed: drive is stopped";
        return;
    }



    // Масштабируем значение от 0-100 до 0-16384
    quint16 scaledValue = static_cast<quint16>((newValue / 3000.0) * MAX_SPEED_VALUE);

    // Создаем запрос на запись нового значения в регистр скорости
    QModbusDataUnit writeRequest(QModbusDataUnit::HoldingRegisters, REG_SPEED, 1);
    writeRequest.setValue(0, scaledValue);

    if (auto *reply = modbusDevice->sendWriteRequest(writeRequest, 1)) {
        connect(reply, &QModbusReply::finished, this, [newValue, reply]() {
            if (reply->error() == QModbusDevice::NoError) {
                qDebug() << "Successfully wrote new speed value:" << newValue << "RPM";
            } else {
                qDebug() << "Failed to write speed value:" << reply->errorString();
            }
            reply->deleteLater();
        });
    }
}

void MainWindow::sendSpeedChange(qreal speed)
{
    qDebug() << "Speed change requested:" << speed;
    if (!modbusDevice || !userSelected || !isRunning) return;{
        qDebug() << "Cannot change speed: device not ready";
        return;
    }

    // Проверяем диапазон
    if (speed < 0 || speed > 3000) {  // Теперь диапазон 0-3000 об/мин
        qDebug() << "Speed value out of range:" << speed;
        return;
    }

    // Преобразуем обороты (0-3000) в значение регистра (0-16384)
    quint16 scaledSpeed = static_cast<quint16>((speed / 3000.0) * MAX_SPEED_VALUE);

    // Записываем в регистр скорости
    QModbusDataUnit writeRequest(QModbusDataUnit::HoldingRegisters, REG_SPEED, 1);
    writeRequest.setValue(0, scaledSpeed);

    if (auto *reply = modbusDevice->sendWriteRequest(writeRequest, 1)) {
        connect(reply, &QModbusReply::finished, this, [speed, reply]() {
            if (reply->error() == QModbusDevice::NoError) {
                qDebug() << "Successfully set speed to" << speed << "RPM";
            } else {
                qDebug() << "Failed to set speed:" << reply->errorString();
            }
            reply->deleteLater();
        });
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
    statisticsWindow->loadUsers();
}



void MainWindow::setupStatusBar()
{
    // Создаем постоянные виджеты для статусбара
    QLabel *versionLabel = new QLabel("Версия 1.2.0", this);
    statusIndicator = new QLabel(this);

    // Создаем лейбл для информации о подключении
    QLabel *connectionInfoLabel = new QLabel(this);


    // Устанавливаем иконку статуса
    QPixmap redIcon("C:/Qt/Raboti/vfd/icon/icon22.svg");
    statusIndicator->setPixmap(redIcon);
    statusIndicator->setPixmap(redIcon.scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    // Добавляем все элементы в статусбар в нужном порядке
    //statusBar()->addWidget(spacer);

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
        connect(this, &MainWindow::progressbars4, statisticTwoWindow, &statistictwo::receiveProgressbars4);
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
    ui->progressBar4->setEnabled(false);
    ui->startButton->setEnabled(false);
    ui->stopButton->setEnabled(false);
    ui->resetButton->setEnabled(false);
    ui->speedInput->setEnabled(false);
    ui->setSpeedButton->setEnabled(false);
    ui->disconnectButton->setEnabled(false);
    ui->menustatistictwo->setEnabled(false);
    ui->menuwarnings->setEnabled(false);
    ui->menuAdmin->setEnabled(false);






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
    ui->progressBar4->setEnabled(true);
    ui->startButton->setEnabled(true);
    ui->stopButton->setEnabled(true);
    ui->resetButton->setEnabled(true);
    ui->speedInput->setEnabled(true);
    ui->setSpeedButton->setEnabled(true);
    ui->disconnectButton->setEnabled(true);
    ui->menustatistictwo->setEnabled(true);
    ui->menuwarnings->setEnabled(true);
    ui->menuAdmin->setEnabled(true);


    statusBar()->showMessage("Пользователь выбран: " + currentUser, 5000);
}

void MainWindow::setCurrentUser(const QString &username)
{
    currentUser = username;
    userSelected = true;

    // Проверяем, является ли пользователь администратором

    QSqlQuery query(db);

    query.prepare("SELECT role FROM users WHERE username = :username");

    query.bindValue(":username", username);



    if (query.exec() && query.next()) {

        isAdminUser = (query.value(0).toString().toLower() == "admin");

    }


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

    QSqlQuery query(db);
    QString tableName = "motor_data_" + username.toLower();

    // Обновленная структура с новыми полями
    QString createTableQuery = QString(
                                   "CREATE TABLE IF NOT EXISTS \"%1\" ("
                                   "id SERIAL PRIMARY KEY, "
                                   "control_word INTEGER, "     // Регистр 0 - управление
                                   "status_word INTEGER, "      // Регистр 1 - статус
                                   "speed INTEGER, "            // Регистр 2 - обороты
                                   "amperage INTEGER, "         // Регистр 3 - ток (progress1)
                                   "voltage INTEGER, "          // Регистр 4 - напряжение (progress2)
                                   "temperature INTEGER, "      // Регистр 5 - температура
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

void MainWindow::insertDataToUserTable(const QString &username,
                                       quint16 controlWord,    // Регистр 0
                                       quint16 statusWord,     // Регистр 1
                                       int motorSpeed,         // Регистр 2
                                       int amperage,           // Регистр 3
                                       int voltage,            // Регистр 4
                                       int temperature)        // Регистр 5
{
    if (!userSelected || username.isEmpty()) {
        qDebug() << "Skipping data insert - no user selected or empty username";
        return;
    }

    QString tableName = "motor_data_" + username.toLower();
    QSqlQuery query(db);

    QString queryStr = QString(
                           "INSERT INTO \"%1\" "
                           "(control_word, status_word, speed, amperage, voltage, temperature) "
                           "VALUES ($1, $2, $3, $4, $5, $6)"
                           ).arg(tableName);

    query.prepare(queryStr);

    query.bindValue(0, controlWord);
    query.bindValue(1, statusWord);
    query.bindValue(2, motorSpeed);
    query.bindValue(3, amperage);
    query.bindValue(4, voltage);
    query.bindValue(5, temperature);

    if (!query.exec()) {
        qDebug() << "Database error when inserting data for user" << username
                 << ":" << query.lastError().text()
                 << "\nQuery was:" << query.lastQuery();
    } else {
        qDebug() << "Successfully inserted data for user" << username
                 << ": control=" << controlWord
                 << ", status=" << statusWord
                 << ", speed=" << motorSpeed
                 << ", amperage=" << amperage
                 << ", voltage=" << voltage
                 << ", temperature=" << temperature;
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
        QString info = QString("%1 : %2    Пакеты : %3    Ошибки : %4")
        .arg(type)
            .arg(address)
            .arg(packets)
            .arg(errors);
        connectionLabel->setText(info);
    }
}

void MainWindow::startDrive()
{
    qDebug() << "Starting drive...";
    if (!modbusDevice || !userSelected) {
        qDebug() << "Cannot start drive: device not ready or user not selected";
        return;
    }

    QModbusDataUnit writeRequest(QModbusDataUnit::HoldingRegisters, REG_CONTROL, 1);
    writeRequest.setValue(0, CMD_START);  // Должно записать 15 (0x000F)
    qDebug() << "Sending START command (decimal:" << CMD_START << ") to register" << REG_CONTROL;

    if (auto *reply = modbusDevice->sendWriteRequest(writeRequest, 1)) {
        connect(reply, &QModbusReply::finished, this, [this, reply]() {
            if (reply->error() == QModbusDevice::NoError) {
                qDebug() << "Successfully sent START command";
                // Меняем цвет текста кнопок
                ui->startButton->setStyleSheet("color: #00FF00;"); // Зеленый
                ui->stopButton->setStyleSheet("color: #FFFFFF;");  // Белый

                // Проверяем статус после отправки команды
                QModbusDataUnit readRequest(QModbusDataUnit::HoldingRegisters, REG_STATUS, 1);
                if (auto *statusReply = modbusDevice->sendReadRequest(readRequest, 1)) {
                    connect(statusReply, &QModbusReply::finished, this, [statusReply]() {
                        if (statusReply->error() == QModbusDevice::NoError) {
                            const QModbusDataUnit unit = statusReply->result();
                            quint16 status = unit.value(0);
                            qDebug() << "Status after START:"
                                     << "decimal:" << status
                                     << "hex:" << QString("0x%1").arg(status, 4, 16, QChar('0'));
                        }
                        statusReply->deleteLater();
                    });
                }
            } else {
                qDebug() << "Failed to send START command:" << reply->errorString();
                // Если произошла ошибка, возвращаем кнопки в исходное состояние
                ui->startButton->setStyleSheet("color: #FFFFFF;"); // Белый
                ui->stopButton->setStyleSheet("color: #FFFFFF;");  // Белый
            }
            reply->deleteLater();
        });
    }
}

void MainWindow::stopDrive()
{
    if (!modbusDevice || !userSelected) return;

    qDebug() << "Stopping drive...";
    QModbusDataUnit writeRequest(QModbusDataUnit::HoldingRegisters, REG_CONTROL, 1);
    writeRequest.setValue(0, CMD_STOP);  // 0x0000

    if (auto *reply = modbusDevice->sendWriteRequest(writeRequest, 1)) {
        connect(reply, &QModbusReply::finished, this, [this, reply]() {
            if (reply->error() == QModbusDevice::NoError) {
                qDebug() << "Successfully sent STOP command";
                isRunning = false;  // Явно устанавливаем флаг
                // Меняем цвет текста кнопок
                ui->stopButton->setStyleSheet("color: #FF0000;"); // Красный
                ui->startButton->setStyleSheet("color: #FFFFFF;"); // Белый

                // Сбрасываем скорость в 0
                QModbusDataUnit speedRequest(QModbusDataUnit::HoldingRegisters, REG_SPEED, 1);
                speedRequest.setValue(0, 0);
                if (auto *speedReply = modbusDevice->sendWriteRequest(speedRequest, 1)) {
                    connect(speedReply, &QModbusReply::finished, this, [speedReply]() {
                        speedReply->deleteLater();
                    });
                }

                statusBar()->showMessage("Привод остановлен", 2000);

                // Проверяем статус после остановки
                QModbusDataUnit readRequest(QModbusDataUnit::HoldingRegisters, REG_STATUS, 1);
                if (auto *statusReply = modbusDevice->sendReadRequest(readRequest, 1)) {
                    connect(statusReply, &QModbusReply::finished, this, [this, statusReply]() {
                        if (statusReply->error() == QModbusDevice::NoError) {
                            const QModbusDataUnit unit = statusReply->result();
                            quint16 status = unit.value(0);
                            qDebug() << "Status after STOP:"
                                     << QString("0x%1").arg(status, 4, 16, QChar('0'));
                            updateDriveStatus(status);
                        }
                        statusReply->deleteLater();
                    });
                }
            } else {
                qDebug() << "Failed to stop drive:" << reply->errorString();

                ui->startButton->setStyleSheet("color: #FFFFFF;"); // Белый
                ui->stopButton->setStyleSheet("color: #FFFFFF;");  // Белый
            }
            reply->deleteLater();
        });
    }
}

void MainWindow::resetDrive()
{
    if (!modbusDevice || !userSelected) return;

    QModbusDataUnit writeRequest(QModbusDataUnit::HoldingRegisters, REG_CONTROL, 1);
    writeRequest.setValue(0, CMD_RESET);

    if (auto *reply = modbusDevice->sendWriteRequest(writeRequest, 1)) {
        connect(reply, &QModbusReply::finished, this, [this, reply]() {
            if (reply->error() == QModbusDevice::NoError) {
                qDebug() << "Successfully reset drive";
                statusBar()->showMessage("Привод сброшен", 2000);
            } else {
                qDebug() << "Failed to reset drive:" << reply->errorString();
            }
            reply->deleteLater();
        });
    }
}

void MainWindow::updateDriveStatus(quint16 statusWord)
{
    bool ready = statusWord & STATUS_READY;
    bool running = statusWord & STATUS_RUNNING;
    bool error = statusWord & STATUS_ERROR;


    qDebug() << "Drive status bits:";
    qDebug() << "Status Word:" << QString("0x%1").arg(statusWord, 4, 16, QChar('0'));
    qDebug() << "Ready bit:" << ready;
    qDebug() << "Running bit:" << running;
    qDebug() << "Error bit:" << error;

    QString statusText;
    QString iconPath;
    if (error) {
        statusText = "ОШИБКА";
        iconPath = "C:/Qt/Raboti/vfd/icon/error.svg";
        statusBar()->showMessage("Ошибка привода!", 2000);
    } else if (running) {
        statusText = "РАБОТА";
        iconPath = "C:/Qt/Raboti/vfd/icon/running.svg";
        isRunning = true;
    } else if (ready) {
        statusText = "ГОТОВ";
        iconPath = "C:/Qt/Raboti/vfd/icon/ready.svg";
        isRunning = false;
    } else {
        statusText = "НЕ ГОТОВ";
        iconPath = "C:/Qt/Raboti/vfd/icon/notready.svg";
        isRunning = false;
    }

    qDebug() << "Status changed to:" << statusText << "isRunning =" << isRunning;

    // Обновляем индикацию состояния
    if (ui->statusLabel) {
        // Создаем изображение нужного размера
        QPixmap combinedPixmap(ui->statusLabel->width(), ui->statusLabel->height());
        combinedPixmap.fill(Qt::transparent);  // Делаем фон прозрачным

        QPainter painter(&combinedPixmap);

        // Рисуем фон
        painter.fillRect(combinedPixmap.rect(), QColor("#2D2D2D"));

        // Устанавливаем цвет текста и шрифт
        painter.setPen(Qt::white);
        QFont font = painter.font();
        font.setPointSize(12);  // Увеличиваем размер шрифта
        font.setBold(true);     // Делаем шрифт жирным
        painter.setFont(font);

        // Загружаем и рисуем иконку
        QPixmap icon(iconPath);
        if (!icon.isNull()) {
            icon = icon.scaled(64, 64, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // Увеличили размер иконки
            painter.drawPixmap(
                ui->statusLabel->width() - 84,  // Увеличили отступ справа
                (ui->statusLabel->height() - 64) / 2,  // Центрируем по вертикали
                icon
                );
        }

        // Рисуем текст (с увеличенным отступом слева)
        painter.drawText(
            QRect(20, 0, ui->statusLabel->width() - 94, ui->statusLabel->height()),  // Увеличили отступы
            Qt::AlignVCenter | Qt::AlignLeft,
            statusText
            );

        // Устанавливаем результат в label
        ui->statusLabel->setPixmap(combinedPixmap);
    }

    // Обновляем статусбар
    statusBar()->showMessage(statusText);
}

void MainWindow::onModbusStateChanged(QModbusDevice::State state)
{
    qDebug() << "Modbus device state changed:" << state;
    if (state == QModbusDevice::ConnectedState) {
        isRunning = false;  // Явно устанавливаем флаг при подключении
        statusBar()->showMessage("Устройство подключено.");
        qDebug() << "Устройство подключено.";

        // Сбрасываем скорость в 0 при подключении
        QModbusDataUnit writeRequest(QModbusDataUnit::HoldingRegisters, REG_SPEED, 1);
        writeRequest.setValue(0, 0);
        if (auto *reply = modbusDevice->sendWriteRequest(writeRequest, 1)) {
            connect(reply, &QModbusReply::finished, this, [reply]() {
                reply->deleteLater();
            });
        }
    } else if (state == QModbusDevice::UnconnectedState) {
        isRunning = false;  // Сбрасываем флаг при отключении
        statusBar()->showMessage("Устройство отключено.");
        qDebug() << "Устройство отключено.";
    }
}

void MainWindow::on_disconnectButton_clicked()
{
    if (!modbusDevice) return;

    qDebug() << "Disconnecting device...";

    // Сначала останавливаем привод
    if (isRunning) {
        stopDrive();
    }

    // Отключаем устройство
    modbusDevice->disconnectDevice();

    // Обновляем иконку на красную при отключении
    if (statusIndicator) {
        QPixmap redIcon("C:/Qt/Raboti/vfd/icon/icon22.jpg"); // Иконка для состояния "отключено"
        statusIndicator->setPixmap(redIcon);
        statusIndicator->setPixmap(redIcon.scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    // Сбрасываем флаги
    //isRunning = false;

    // Обновляем UI
    //statusBar()->showMessage("Устройство отключено");

    // Отключаем элементы управления
    disableControls();
}









void MainWindow::on_actionRegister_triggered()
{
    Registration registrationDialog(this);
    registrationDialog.exec();
}
void MainWindow::on_actionadminpanel_triggered()
{
    if (!isAdminUser) {

        QMessageBox::warning(this, "Ошибка",

                             "Доступ запрещен. Необходимы права администратора.");

        return;

    }
    Admin adminDialog(this);
    adminDialog.exec();

}







void MainWindow::on_actionWarnings_triggered()
{
    int userId = currentUserId; // Получите ID текущего пользователя
    ErrorWindow errorWindow(userId, this); // Передаем ID пользователя и родительский виджет
    errorWindow.exec(); // Открываем окно

}


void MainWindow::readErrorStatus() {
    if (!modbusDevice) {
        qDebug() << "Modbus device is not initialized!";
        return;
    }

    // Чтение регистров ошибок
    QModbusDataUnit readRequest(QModbusDataUnit::HoldingRegisters, 16380, 5); // Чтение 5 регистров начиная с 16380
    if (auto *reply = modbusDevice->sendReadRequest(readRequest, 1)) {
        connect(reply, &QModbusReply::finished, this, [this, reply]() {
            if (reply->error() == QModbusDevice::NoError) {
                // Обработка полученных данных
                const QModbusDataUnit &dataUnit = reply->result();
                for (int i = 0; i < dataUnit.valueCount(); ++i) {
                    quint16 errorCode = dataUnit.value(i);
                    // Сохранение ошибки в базу данных
                    saveErrorToDatabase(errorCode);
                }
            } else {
                qDebug() << "Error reading error status:" << reply->errorString();
                qDebug() << "Modbus Exception Code:" << reply->error();
            }
            reply->deleteLater();
        });
    } else {
        qDebug() << "Error sending read request:" << reply->errorString();
    }
}



void MainWindow::saveErrorToDatabase(int errorCode) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO errorlog (userid, errorcode, errordescription, timestamp) VALUES (:userid, :errorcode, :description, CURRENT_TIMESTAMP)");

    query.bindValue(":userid", currentUserId); // Предполагается, что у вас есть переменная currentUserId
    query.bindValue(":errorcode", errorCode);

    // Определите описание ошибки на основе errorCode
    QString errorDescription;
    switch (errorCode) {
    case 1:
        errorDescription = "Низкое напряжение";
        break;
    case 2:
        errorDescription = "Обрыв нулевого провода";
        break;
    case 3:
        errorDescription = "Перегрузка двигателя";
        break;
    case 4:
        errorDescription = "Короткое замыкание";
        break;
    case 5:
        errorDescription = "Перегрузка инвертора";
        break;
    default:
        errorDescription = "Неизвестная ошибка";
        break;
    }

    query.bindValue(":description", errorDescription);

    if (!query.exec()) {
        qDebug() << "Ошибка при сохранении в errorlog:" << query.lastError().text();
    } else {
        qDebug() << "Ошибка сохранена в errorlog:" << errorCode;
    }
}




void MainWindow::on_actionExportReport_triggered()

{

    if (!userSelected || currentUser.isEmpty()) {

        QMessageBox::warning(this, "Ошибка", "Сначала выберите пользователя");

        return;

    }



    QString templatePath = QFileDialog::getOpenFileName(

        this,

        "Выберите шаблон отчета",

        "",

        "Word Documents (*.docx)"

        );



    if (templatePath.isEmpty()) return;



    QString outputPath = QFileDialog::getSaveFileName(

        this,

        "Сохранить отчет как",

        QString("Report_%1_%2.docx")

            .arg(currentUser)

            .arg(QDateTime::currentDateTime().toString("dd_MM_yyyy_hh_mm")),

        "Word Documents (*.docx)"

        );



    if (outputPath.isEmpty()) return;




}







void MainWindow::onManualSpeedEntered()
{
    // Получаем введенное значение скорости
    bool ok;
    int speed = ui->speedInput->text().toInt(&ok);

    // Проверяем, успешно ли преобразовано число
    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Введите корректное числовое значение");
        return;
    }

    // Проверяем диапазон
    if (speed < 0 || speed > 3000) {
        QMessageBox::warning(this, "Ошибка", "Значение скорости должно быть от 0 до 3000");
        return;
    }

    // Преобразуем скорость в значение для регистра
    int speedValue = (speed * MAX_SPEED_VALUE) / 3000;

    // Отправляем команду на изменение скорости
    QModbusDataUnit writeRequest(QModbusDataUnit::HoldingRegisters, REG_SPEED, 1);
    writeRequest.setValue(0, speedValue);

    if (auto *reply = modbusDevice->sendWriteRequest(writeRequest, 1)) {
        connect(reply, &QModbusReply::finished, this, [this, reply, speed]() {
            if (reply->error() == QModbusDevice::NoError) {
                ui->statusbar->showMessage(QString("Установлена скорость: %1 об/мин").arg(speed), 3000);
            } else {
                ui->statusbar->showMessage(QString("Ошибка установки скорости: %1").arg(reply->errorString()), 3000);
            }
            reply->deleteLater();
        });
    }
}









