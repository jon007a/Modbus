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
    void addUser();
    void selectUser();
    void loadUsers();

private:
    Ui::Statistic *ui;
    QString currentUser;
    QSqlDatabase db;

    bool initDatabase();
    bool createUsersTable();
};

#endif // STATISTIC_H

