#include "connectionsettings.h"
#include "ui_connectionsettings.h"
#include <QSerialPort>

ConnectionSettings::ConnectionSettings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConnectionSettings)
{
    setWindowIcon(QIcon("C:/Qt/Raboti/vfd/pictures/icon3.png"));
    ui->setupUi(this);

    // Добавляем два варианта выбора: RTU и TCP
    ui->connectionTypeComboBox->addItem("RTU");
    ui->connectionTypeComboBox->addItem("TCP");

    // Настройка списка параметров для baud rate
    ui->baudRateComboBox->addItem("1200", 1200);
    ui->baudRateComboBox->addItem("2400", 2400);
    ui->baudRateComboBox->addItem("4800", 4800);
    ui->baudRateComboBox->addItem("9600", 9600);   // стандартное значение
    ui->baudRateComboBox->addItem("19200", 19200);
    ui->baudRateComboBox->addItem("38400", 38400);
    ui->baudRateComboBox->addItem("57600", 57600);
    ui->baudRateComboBox->addItem("115200", 115200);

    // Настройка списка параметров для data bits
    ui->dataBitsComboBox->addItem("5", QSerialPort::Data5);
    ui->dataBitsComboBox->addItem("6", QSerialPort::Data6);
    ui->dataBitsComboBox->addItem("7", QSerialPort::Data7);
    ui->dataBitsComboBox->addItem("8", QSerialPort::Data8);  // стандартное значение

    // Настройка списка параметров для stop bits
    ui->stopBitsComboBox->addItem("1", QSerialPort::OneStop);
    ui->stopBitsComboBox->addItem("1.5", QSerialPort::OneAndHalfStop);
    ui->stopBitsComboBox->addItem("2", QSerialPort::TwoStop);  // стандартное значение

    // Настройка списка параметров для parity
    ui->parityComboBox->addItem("None", QSerialPort::NoParity);  // стандартное значение
    ui->parityComboBox->addItem("Even", QSerialPort::EvenParity);
    ui->parityComboBox->addItem("Odd", QSerialPort::OddParity);

    // Подключаем слот для смены виджетов при изменении типа подключения
    connect(ui->connectionTypeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &ConnectionSettings::on_connectionTypeChanged);

    // По умолчанию показываем виджеты для RTU
    ui->comPortSpinBox->show();
    ui->ipAddressLineEdit->hide();
}

void ConnectionSettings::on_connectionTypeChanged() {
    QString connectionType = ui->connectionTypeComboBox->currentText();

    if (connectionType == "RTU") {
        ui->comPortSpinBox->show();
        ui->ipAddressLineEdit->hide();
    } else if (connectionType == "TCP") {
        ui->comPortSpinBox->hide();
        ui->ipAddressLineEdit->show();
    }
}

void ConnectionSettings::on_applyButton_clicked() {
    QString connectionType = ui->connectionTypeComboBox->currentText();
    if (connectionType == "TCP") {
        QString ipAddressWithPort = ui->ipAddressLineEdit->text();  // Получаем введенную строку
        QStringList parts = ipAddressWithPort.split(":");
        if (parts.size() == 2) {
            QString ipAddress = parts[0];  // IP-адрес
            int port = parts[1].toInt();   // Порт

            // Проверяем, что IP-адрес и порт корректны
            if (ipAddress.isEmpty() || port <= 0) {
                qDebug() << "Invalid IP address or port.";
                return;
            }

            // Передаем параметры подключения
            emit settingsApplied(connectionType, -1, -1, -1, -1, -1, ipAddress, port);  // Отправляем IP и порт
        } else {
            qDebug() << "Invalid format for IP address and port.";
        }
    } else {
        // Обработка для RTU
        int comPort = ui->comPortSpinBox->value();
        int baudRate = ui->baudRateComboBox->currentData().toInt();
        int dataBits = ui->dataBitsComboBox->currentData().toInt();
        int stopBits = ui->stopBitsComboBox->currentData().toInt();
        int parity = ui->parityComboBox->currentData().toInt();

        // Передаем параметры подключения для RTU
        emit settingsApplied(connectionType, comPort, baudRate, dataBits, stopBits, parity, "", 0);
    }

    accept();
}

ConnectionSettings::~ConnectionSettings()
{
    delete ui;
}
