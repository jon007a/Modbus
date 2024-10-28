#ifndef CONNECTIONSETTINGS_H
#define CONNECTIONSETTINGS_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class ConnectionSettings;
}
QT_END_NAMESPACE

class ConnectionSettings : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionSettings(QWidget *parent = nullptr);
    ~ConnectionSettings();

signals:
    void settingsApplied(QString connectionType, int comPort, int baudRate, int dataBits, int stopBits, int parity, QString ipAddress, int port);

private slots:
    void on_applyButton_clicked();
    void on_connectionTypeChanged();

private:
    Ui::ConnectionSettings *ui;
};

#endif // CONNECTIONSETTINGS_H
