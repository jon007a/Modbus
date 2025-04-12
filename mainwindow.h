#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQuickWidget> // Добавляем этот заголовок
#include <QModbusClient>
#include <QModbusDataUnit>
#include <QModbusDevice>
#include <QModbusTcpClient>
#include <QModbusReply>
#include <QModbusRtuSerialClient>
#include <QtGlobal>
#include <QtSql/QSqlDatabase>
#include <QLabel>
#include "statistic.h" // Включаем заголовок Statistic
#include "statistictwo.h"
#include <QList>
#include <QDesktopServices>
#include <QUrl>
#include <QtGlobal>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <admin.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    void resizeEvent(QResizeEvent *event) override; // Добавьте это

private slots:
    void on_actionrtu_triggered();
    void applySettings(QString connectionType, int comPort, int baudRate, int dataBits, int stopBits, int parity, QString ipAddress, int port);
    void onModbusReadReady(); // Слот для обработки данных с Modbus
    void onSliderValueChanged(int newValue);
    void sendSpeedChange(qreal speed);
    void requestDataFromModbus();
    void onSlaveConnected();
    void onSlaveDisconnected();
    void on_action_triggered();
    void on_action_2_triggered();
    bool createUserTable(const QString &username); // Новый слот для создания таблицы пользователя
    void on_actionOpenManual_triggered();
    void on_startButton_clicked() { startDrive(); }
    void on_stopButton_clicked() { stopDrive(); }
    void on_resetButton_clicked() { resetDrive(); }
    void onModbusStateChanged(QModbusDevice::State state);
    void on_disconnectButton_clicked();// Слот для кнопки отключения
    void on_actionRegister_triggered();
    void on_actionExportReport_triggered(); // word
    void onManualSpeedEntered();

    void on_actionadminpanel_triggered();

    void on_actionWarnings_triggered();
    void saveErrorToDatabase(int errorCode); // Метод для сохранения ошибки в БД
    void readErrorStatus();
    //void setCurrentUserr(int userId);


signals:
    void speedChanged(qreal speed); // Добавьте этот сигнал
    void motorSpeedUpdated(int motorSpeed);
    void progressbars(int progressValue);
    void progressbars2(int progressValue2);
    void progressbars4(int progressValue4);
    void slaveConnected();    // Сигнал, когда устройство подключено
    void slaveDisconnected(); // Сигнал, когда устройство отключено

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void setCurrentUser(const QString &username); // Новый метод




private:
    Ui::MainWindow *ui;


    QQuickWidget *qmlWidget; // Добавляем QQuickWidget как член класса
    QModbusClient *modbusDevice; //Клиент для работы с модбас
    void setupModbusClient();
    void setupDatabaseConnection(); // Метод для настройки подключения к БД
    Statistic *statisticsWindow = nullptr; // Указатель на окно статистики
    QSqlDatabase db;
    void insertFanSpeedToDatabase(int fanSpeed);
    void setupStatusBar();
    QLabel *statusIndicator; // Индикатор статуса подключения
    statistictwo *statisticTwoWindow = nullptr;
    QString currentUser; // Добавляем текущего пользователя
    bool userSelected; // Флаг выбора пользователя

    // Константы для регистров Modbus
    const int REG_CONTROL = 0;    // Control Word
    const int REG_STATUS = 1;     // Status Word
    const int REG_SPEED = 2;      // Регистр скорости
    const int REG_CURRENT = 3;    // Регистр тока
    const int REG_VOLTAGE = 4;    // Регистр напряжения
    const int REG_TEMP = 5;      // Регистр температуры

    // Константы для Control Word
    const quint16 CMD_STOP = 0x0000;     // Команда Stop // 0 в десятичной
    const quint16 CMD_START = 0x000F;    // Команда Start  // 15 в десятичной
    const quint16 CMD_RESET = 0x0080;    // Сброс ошибок  // 128 в десятичной

    // Маски для Status Word
    const quint16 STATUS_READY = 0x0001;    // Готов к работе
    const quint16 STATUS_RUNNING = 0x0002;   // В работе
    const quint16 STATUS_ERROR = 0x0008;     // Ошибка

    // Константы для преобразования значений
    const double MAX_SPEED_VALUE = 16384.0;  // Максимальное значение скорости
    const double CURRENT_SCALE = 0.01;       // Множитель для тока

    // Флаги состояния
    bool isConnected = false;
    bool isRunning = false;


    void on_userSelectionChanged();



    // Добавляем счетчики пакетов
    int successPackets = 0;
    int errorPackets = 0;

    void startDrive();
    void stopDrive();
    void resetDrive();
    void updateDriveStatus(quint16 statusWord);


    void setupComboBox();


    void insertDataToUserTable(const QString &username,
                               quint16 controlWord,    // Регистр 0
                               quint16 statusWord,     // Регистр 1
                               int motorSpeed,         // Регистр 2
                               int amperage,           // Регистр 3
                               int voltage,            // Регистр 4
                               int temperature);       // Регистр 5


    void disableControls(); // Метод для отключения элементов управления
    void enableControls(); // Метод для включения элементов управления
    QLabel *connectionLabel;


    void updateConnectionInfo(const QString &type, const QString &address, int packets, int errors); // Добавляем объявление метода
    static QString generateConnectionName() {
        static int counter = 0;
        return QString("Connection_%1").arg(++counter);
    }

    int currentUserId; // Храните ID текущего пользователя
    bool isAdminUser;
    QAction *adminAction;
};

#endif // MAINWINDOW_H
