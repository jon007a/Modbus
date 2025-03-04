#ifndef STATISTIC_H
#define STATISTIC_H

#include <QMainWindow>
#include <QStringList>
#include <QSqlDatabase>

class MainWindow;

namespace Ui {
class Statistic;
}

class Statistic : public QMainWindow
{
    Q_OBJECT

public:
    explicit Statistic(QWidget *parent = nullptr);
    ~Statistic();

signals:
    void userSelected(const QString &username);


private slots:

    void selectUser();
    void loadUsers();


private:
    Ui::Statistic *ui;
    QString currentUser;
    QSqlDatabase db;
    bool checkPassword(const QString &username, const QString &password);
    QString hashPassword(const QString &password);
    bool initDatabase();
    bool createUsersTable();
    static QString generateConnectionName() {
        static int counter = 0;
        return QString("Statistic_Connection_%1").arg(++counter);
    }
};

#endif // STATISTIC_H

