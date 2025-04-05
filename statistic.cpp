#include "statistic.h"
#include "ui_statistic.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QCryptographicHash>

Statistic::Statistic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Statistic)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("C:/Qt/Raboti/vfd/pictures/selection.png"));
    connect(ui->selectUserButton, &QPushButton::clicked, this, &Statistic::selectUser);

    // Инициализация базы данных и загрузка пользователей
    if (initDatabase()) {
        loadUsers();
    }
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
    // Генерируем уникальное имя для подключения
    QString connectionName = generateConnectionName();

    db = QSqlDatabase::addDatabase("QPSQL", connectionName); // Убедитесь, что драйвер PostgreSQL подключен
    db.setHostName("localhost");
    db.setDatabaseName("statisticbase"); // Замените на имя вашей БД
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
    QSqlQuery query(db);
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

    QSqlQuery query(db);
    // Простой запрос для выбора всех пользователей
    query.prepare("SELECT username FROM users ORDER BY username");

    if (query.exec()) {
        while (query.next()) {
            QString username = query.value(0).toString();
            ui->userComboBox->addItem(username);
            qDebug() << "Loaded user:" << username; // Отладочное сообщение
        }
        qDebug() << "Total users loaded:" << ui->userComboBox->count();
    } else {
        qDebug() << "Failed to load users:" << query.lastError().text();
    }
}

QString Statistic::hashPassword(const QString &password)
{
    return QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
}

void Statistic::selectUser()
{
    QString selectedUser = ui->userComboBox->currentText();
    QString enteredPassword = ui->passwordLineEdit->text();
    if (selectedUser.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Выберите пользователя");
        return;
    }

    // Проверяем существование пользователя
    QSqlQuery query(db);
    query.prepare("SELECT password_hash FROM users WHERE username = :username");
    query.bindValue(":username", selectedUser);

    if (query.exec() && query.next()) {
        QString storedPasswordHash = query.value(0).toString();

        // Проверяем, совпадает ли введенный пароль с хешем
        if (hashPassword(enteredPassword) == storedPasswordHash) {
            currentUser = selectedUser;
            emit userSelected(currentUser);
            QMessageBox::information(this, "Успех", "Выбран пользователь: " + currentUser);
        } else {
            QMessageBox::warning(this, "Ошибка", "Неверный пароль");
        }
    } else {
        QMessageBox::warning(this, "Ошибка", "Пользователь не найден");
    }
}




