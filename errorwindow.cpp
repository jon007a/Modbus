#include "errorwindow.h"
#include "ui_errorwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextDocumentWriter>
#include <QTextTable>

ErrorWindow::ErrorWindow(int userId,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorWindow),
    currentUserId(userId)

{
    ui->setupUi(this);
    setWindowIcon(QIcon("C:/Qt/Raboti/vfd/pictures/error.png"));
    initDatabase(); // Инициализация базы данных
    loadUsers(); // Загрузка пользователей в comboBox
    connect(ui->refreshButton, &QPushButton::clicked, this, &ErrorWindow::refreshErrorList);
    connect(ui->exportButton, &QPushButton::clicked, this, &ErrorWindow::exportErrors);
    connect(ui->startDateEdit, &QDateEdit::dateChanged, this, &ErrorWindow::filterErrorsByDate);
    connect(ui->endDateEdit, &QDateEdit::dateChanged, this, &ErrorWindow::filterErrorsByDate);
}

void ErrorWindow::initDatabase() {

    db = QSqlDatabase::addDatabase("QPSQL", "ErrorWindowConnection"); // Создаем новое подключение

    db.setHostName("localhost");

    db.setDatabaseName("statisticbase");

    db.setUserName("postgres");

    db.setPassword("1234");

    db.setPort(5432);



    if (!db.open()) {

        QMessageBox::critical(this, "Ошибка",

                              "Не удалось подключиться к базе данных: " + db.lastError().text());

    } else {

        qDebug() << "Подключение к базе данных успешно!";

    }

}

void ErrorWindow::loadUsers() {
    if (!db.isOpen()) {

        qDebug() << "База данных не открыта!";

        return; // Не продолжаем, если база данных не доступна

    }



    // Загрузка пользователей из базы данных

    QSqlQuery query(db);
    query.prepare("SELECT id, username FROM Users");

    if (query.exec()) {

        while (query.next()) {

            ui->userComboBox->addItem(query.value(1).toString(), query.value(0));

        }

    } else {

        qDebug() << "Ошибка при загрузке пользователей:" << query.lastError().text();

    }

}

void ErrorWindow::refreshErrorList() {

    if (!db.isOpen()) {

        qDebug() << "База данных не открыта!";

        return; // Не продолжаем, если база данных не доступна

    }

    // Очистка таблицы
    ui->errorTable->setRowCount(0);

    // Получение ошибок из базы данных
    int userId = ui->userComboBox->currentData().toInt();
    QSqlQuery query(db);
    query.prepare("SELECT errorCode, errorDescription, timestamp FROM ErrorLog WHERE userId = :userId ORDER BY timestamp DESC");
    query.bindValue(":userId", userId);
    if (query.exec()) {
        while (query.next()) {
            int row = ui->errorTable->rowCount();
            ui->errorTable->setColumnCount(3); // Установите количество колонок
            ui->errorTable->setHorizontalHeaderLabels(QStringList() << "Код ошибки" << "Описание" << "Время");
            ui->errorTable->insertRow(row);
            ui->errorTable->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->errorTable->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->errorTable->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
            qDebug() << "Error Code:" << query.value(0).toString();
            qDebug() << "Error Description:" << query.value(1).toString();
            qDebug() << "Timestamp:" << query.value(2).toString();
        }
    } else {
        qDebug() << "Ошибка при получении ошибок:" << query.lastError().text();
    }
}

void ErrorWindow::saveErrorToDatabase(int userId, int errorCode, const QString &errorDescription) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO ErrorLog (userid, errorcode, errordescription, timestamp) VALUES (:userId, :errorCode, :errorDescription, CURRENT_TIMESTAMP)");
    query.bindValue(":userId", userId);
    query.bindValue(":errorCode", errorCode);
    query.bindValue(":errorDescription", errorDescription);
    if (!query.exec()) {
        qDebug() << "Ошибка при сохранении ошибки:" << query.lastError().text();
    }
}

void ErrorWindow::filterErrorsByDate() {
    // Очистка таблицы
    ui->errorTable->setRowCount(0);

    int userId = ui->userComboBox->currentData().toInt();
    QDate startDate = ui->startDateEdit->date();
    QDate endDate = ui->endDateEdit->date();

    QSqlQuery query(db);
    query.prepare("SELECT errorCode, errorDescription, timestamp FROM ErrorLog WHERE userId = :userId AND DATE(timestamp) BETWEEN :startDate AND :endDate ORDER BY timestamp DESC");
    query.bindValue(":userId", userId);
    query.bindValue(":startDate", startDate);
    query.bindValue(":endDate", endDate);
    if (query.exec()) {
        while (query.next()) {
            int row = ui->errorTable->rowCount();
            ui->errorTable->insertRow(row);
            ui->errorTable->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->errorTable->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->errorTable->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        }
    } else {
        qDebug() << "Ошибка при фильтрации ошибок:" << query.lastError().text();
    }
}

void ErrorWindow::exportErrors() {

}

ErrorWindow::~ErrorWindow() {
    delete ui; // Удаляем указатель на UI
} 
