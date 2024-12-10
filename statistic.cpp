#include "statistic.h"
#include "ui_statistic.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Statistic::Statistic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Statistic)
{
    ui->setupUi(this);

    // Инициализируем базу данных
    if (!initDatabase()) {
        qDebug() << "Database initialization error: Ne udalos' inicializirovat' bazu dannyh";
        return;
    }

    // Создаем таблицу пользователей если её нет
    if (!createUsersTable()) {
        qDebug() << "Table creation error: Ne udalos' sozdat' tablicu pol'zovateley";
        return;
    }

    loadUsers();

    connect(ui->addUserButton, &QPushButton::clicked, this, &Statistic::addUser);
    connect(ui->selectUserButton, &QPushButton::clicked, this, &Statistic::selectUser);
}

Statistic::~Statistic()
{
    if (db.isOpen()) {
        db.close();
    }
    delete ui;
}

bool Statistic::initDatabase()
{
    db = QSqlDatabase::addDatabase("QPSQL"); // Убедитесь, что драйвер PostgreSQL подключен
    db.setHostName("localhost");
    db.setDatabaseName("Statisticbase"); // Замените на имя вашей БД
    db.setUserName("postgres"); // Замените на ваше имя пользователя
    db.setPassword("1234"); // Замените на ваш пароль
    db.setPort(5432);

    if (!db.open()) {
        qDebug() << "Oshibka otkrytiya bazy dannyh:" << db.lastError().text();
        return false;
    }
    return true;
}

bool Statistic::createUsersTable()
{
    QSqlQuery query;
    QString createTableQuery =
        "CREATE TABLE IF NOT EXISTS users ("
        "id SERIAL PRIMARY KEY,"
        "username TEXT NOT NULL UNIQUE,"
        "created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP"
        ")";

    if (!query.exec(createTableQuery)) {
        qDebug() << "Oshibka sozdaniya tablicy:" << query.lastError().text();
        return false;
    }
    return true;
}

void Statistic::loadUsers()
{
    ui->userComboBox->clear();

    QSqlQuery query("SELECT username FROM users ORDER BY username");
    while (query.next()) {
        QString username = query.value(0).toString();
        ui->userComboBox->addItem(username);
    }
}

void Statistic::addUser()
{
    QString newUser = ui->newUserLineEdit->text().trimmed();
    if (newUser.isEmpty()) {
        QMessageBox::warning(this, "Error", "Vvedite imya pol'zovatelya");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO users (username) VALUES (:username)");
    query.bindValue(":username", newUser);

    if (!query.exec()) {
        if (query.lastError().databaseText().contains("unique violation")) {
            QMessageBox::warning(this, "Error", "Takoy pol'zovatel' uzhe sushchestvuet");
        } else {
            QMessageBox::warning(this, "Error",
                                 "Ne udalos' dobavit' pol'zovatelya: " + query.lastError().text());
        }
        return;
    }

    ui->newUserLineEdit->clear();
    loadUsers();
    QMessageBox::information(this, "Success", "Pol'zovatel' uspeshno dobavlen");
}

void Statistic::selectUser()
{
    QString selectedUser = ui->userComboBox->currentText();
    if (selectedUser.isEmpty()) {
        QMessageBox::warning(this, "Error", "Vyberite pol'zovatelya");
        return;
    }

    currentUser = selectedUser;
    emit userSelected(currentUser);
    QMessageBox::information(this, "Success", "Vybran pol'zovatel': " + currentUser);
}


