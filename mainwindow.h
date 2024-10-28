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

#include "statistic.h" // Включаем заголовок Statistic


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

    void on_action_triggered();

signals:
    void speedChanged(qreal speed); // Добавьте этот сигнал

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
    QQuickWidget *qmlWidget; // Добавляем QQuickWidget как член класса
    QModbusClient *modbusDevice; //Клиент для работы с модбас
    void setupModbusClient();
    void setupDatabaseConnection(); // Метод для настройки подключения к БД
    Statistic *statisticsWindow = nullptr; // Указатель на окно статистики
    QSqlDatabase db;
    void insertFanSpeedToDatabase(int fanSpeed);

};

#endif // MAINWINDOW_H
