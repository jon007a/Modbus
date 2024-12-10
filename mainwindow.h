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

signals:
    void speedChanged(qreal speed); // Добавьте этот сигнал
    void motorSpeedUpdated(int motorSpeed);
    void progressbars(int progressValue);
    void progressbars2(int progressValue2);
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

    void insertDataToUserTable(const QString &username, int motorSpeed, int progress1, int progress2);
    void disableControls(); // Метод для отключения элементов управления
    void enableControls(); // Метод для включения элементов управления
    QLabel *connectionLabel;
    // Добавляем эти переменные для подсчета пакетов
    int packetCount = 0;
    int errorCount = 0;

    void updateConnectionInfo(const QString &type, const QString &address, int packets, int errors); // Добавляем объявление метода


};

#endif // MAINWINDOW_H
