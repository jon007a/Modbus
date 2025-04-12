#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include <QDebug>
#include "registration.h"

Admin::Admin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Admin)
    , isEditMode(false)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("C:/Qt/Raboti/vfd/pictures/admin.png"));

    // Инициализация базы данных
    initDatabase();
    
    // Загрузка пользователей
    loadUsers();
    
    // Начальное состояние формы
    setFormEnabled(false);
    
    // Подключение сигналов
    connect(ui->userComboBox, &QComboBox::currentTextChanged, 
            this, &Admin::onUserSelected);
    connect(ui->addButton, &QPushButton::clicked, 
            this, &Admin::onAddClicked);
    connect(ui->editButton, &QPushButton::clicked, 
            this, &Admin::onEditClicked);
    connect(ui->deleteButton, &QPushButton::clicked, 
            this, &Admin::onDeleteClicked);
    connect(ui->saveButton, &QPushButton::clicked,
            this, &Admin::onSaveClicked);
    connect(ui->cancelButton, &QPushButton::clicked, 
            this, &Admin::onCancelClicked);
    connect(ui->saveButton, &QPushButton::clicked,
            this, &Admin::saveEmployeeData);
    Registration *registrationDialog = new Registration(this);
    connect(registrationDialog, &Registration::userRegistered, this, &Admin::loadUsers);

    // Инициализация новых полей

    fullNameEdit = ui->fullNameEdit;

    positionEdit = ui->positionEdit;

    otdelEdit = ui->otdelEdit;

    organizationEdit = ui->organizationEdit;
}

Admin::~Admin()
{
    if (db.isOpen()) {
        db.close();
    }
    delete ui;
}

void Admin::initDatabase()
{
    db = QSqlDatabase::addDatabase("QPSQL", "AdminConnection");
    db.setHostName("localhost");
    db.setDatabaseName("statisticbase");
    db.setUserName("postgres");
    db.setPassword("1234");
    db.setPort(5432);

    if (!db.open()) {
        QMessageBox::critical(this, "Ошибка", 
            "Не удалось подключиться к базе данных: " + db.lastError().text());
    }
}

void Admin::loadUsers()
{
    ui->userComboBox->clear();
    
    QSqlQuery query(db);
    query.prepare("SELECT username FROM users ORDER BY username");
    
    if (query.exec()) {
        while (query.next()) {
            ui->userComboBox->addItem(query.value(0).toString());
        }
    } else {
        QMessageBox::warning(this, "Ошибка", 
            "Не удалось загрузить список пользователей: " + query.lastError().text());
    }
}

void Admin::onUserSelected(const QString &username)
{
    if (username.isEmpty()) return;

    // Сначала получаем данные из таблицы users
    QSqlQuery userQuery(db);
    userQuery.prepare("SELECT username, activation_code, role FROM users WHERE username = :username");
    userQuery.bindValue(":username", username);

    if (!userQuery.exec()) {
        QMessageBox::warning(this, "Ошибка", "Не удалось загрузить данные пользователя: " + userQuery.lastError().text());
        return;
    }

    if (userQuery.next()) {
        ui->loginEdit->setText(userQuery.value(0).toString());
        ui->activationEdit->setText(userQuery.value(1).toString());

        QString role = userQuery.value(2).toString();
        int index = ui->roleComboBox->findText(role, Qt::MatchFixedString);
        if (index >= 0) {
            ui->roleComboBox->setCurrentIndex(index);
        }
    } else {
        QMessageBox::warning(this, "Ошибка", "Пользователь не найден.");
        return;
    }

    // Теперь получаем данные из таблицы employees
    QSqlQuery employeeQuery(db);
    employeeQuery.prepare("SELECT fullname, position, otdel, organization FROM employees WHERE username = :username");
    employeeQuery.bindValue(":username", username);

    if (!employeeQuery.exec()) {
        QMessageBox::warning(this, "Ошибка", "Не удалось загрузить данные о сотруднике: " + employeeQuery.lastError().text());
        return;
    }

    if (employeeQuery.next()) {
        ui->positionEdit->setText(employeeQuery.value(1).toString());
        ui->otdelEdit->setText(employeeQuery.value(2).toString());
        ui->organizationEdit->setText(employeeQuery.value(3).toString());
        ui->fullNameEdit->setText(employeeQuery.value(0).toString());
    } else {
        QMessageBox::warning(this, "Ошибка", "Данные о сотруднике не найдены.");
    }

    ui->passwordEdit->clear();
}

void Admin::onAddClicked()
{
    isEditMode = false;
    clearForm();
    setFormEnabled(true);
}

void Admin::onEditClicked()
{
    if (ui->userComboBox->currentText().isEmpty()) {
        QMessageBox::warning(this, "Предупреждение", "Выберите пользователя для редактирования");
        return;
    }
    
    isEditMode = true;
    setFormEnabled(true);
}

void Admin::onDeleteClicked()
{
    QString username = ui->userComboBox->currentText();
    if (username.isEmpty()) {
        QMessageBox::warning(this, "Предупреждение", "Выберите пользователя для удаления");
        return;
    }
    
    if (QMessageBox::question(this, "Подтверждение", 
        "Вы действительно хотите удалить пользователя " + username + "?",
        QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        
        QSqlQuery query(db);

        // Удаление строки из таблицы employees
        query.prepare("DELETE FROM Employees WHERE username = :username");
        query.bindValue(":username", username);

        if (!query.exec()) {
            QMessageBox::critical(this, "Ошибка",
                                  "Не удалось удалить данные о сотруднике: " + query.lastError().text());
            return; // Выход, если не удалось удалить данные о сотруднике
        }

        // Удаление пользователя из таблицы users
        query.prepare("DELETE FROM users WHERE username = :username");
        query.bindValue(":username", username);
        
        if (query.exec()) {
            loadUsers();
            clearForm();
            QMessageBox::information(this, "Успех", "Пользователь успешно удален");
        } else {
            QMessageBox::critical(this, "Ошибка", 
                "Не удалось удалить пользователя: " + query.lastError().text());
        }
    }
}

void Admin::onSaveClicked()
{
    if (!validateInput()) return;
    
    QSqlQuery query(db);
    if (isEditMode) {
        QString updateQuery = "UPDATE users SET username = :new_username";
        if (!ui->passwordEdit->text().isEmpty()) {
            updateQuery += ", password_hash = :password";
        }
        updateQuery += ", activation_code = :activation, role = :role "
                      "WHERE username = :old_username";
        
        query.prepare(updateQuery);
        query.bindValue(":new_username", ui->loginEdit->text());
        query.bindValue(":old_username", ui->userComboBox->currentText());
        if (!ui->passwordEdit->text().isEmpty()) {
            query.bindValue(":password", hashPassword(ui->passwordEdit->text()));
        }
    } else {
        query.prepare("INSERT INTO users (username, password_hash, activation_code, role) "
                     "VALUES (:username, :password, :activation, :role)");
        query.bindValue(":username", ui->loginEdit->text());
        query.bindValue(":password", hashPassword(ui->passwordEdit->text()));
    }
    
    query.bindValue(":activation", ui->activationEdit->text());
    query.bindValue(":role", ui->roleComboBox->currentText().toLower());
    
    if (query.exec()) {
        //loadUsers();
        setFormEnabled(false);
        QMessageBox::information(this, "Успех", 
            isEditMode ? "Данные пользователя обновлены" : "Пользователь добавлен");
    } else {
        QMessageBox::critical(this, "Ошибка", 
            "Не удалось сохранить данные: " + query.lastError().text());
    }
}

void Admin::onCancelClicked()
{
    clearForm();
    setFormEnabled(false);
}

void Admin::clearForm()
{
    ui->loginEdit->clear();
    ui->passwordEdit->clear();
    ui->activationEdit->clear();
    ui->roleComboBox->setCurrentIndex(0);
    //ui->roleComboBox->clear();
    ui->fullNameEdit->clear();
    ui->positionEdit->clear();
    ui->otdelEdit->clear();
    ui->organizationEdit->clear();
}

void Admin::setFormEnabled(bool enabled)
{
    ui->loginEdit->setEnabled(enabled);
    ui->passwordEdit->setEnabled(enabled);
    ui->activationEdit->setEnabled(enabled);
    ui->roleComboBox->setEnabled(enabled);
    ui->organizationEdit->setEnabled(enabled);
    ui->otdelEdit->setEnabled(enabled);
    ui->positionEdit->setEnabled(enabled);
    ui->fullNameEdit->setEnabled(enabled);
    ui->saveButton->setEnabled(enabled);
    ui->cancelButton->setEnabled(enabled);
    
    ui->addButton->setEnabled(!enabled);
    ui->editButton->setEnabled(!enabled);
    ui->deleteButton->setEnabled(!enabled);
}

QString Admin::hashPassword(const QString &password)
{
    return QString(QCryptographicHash::hash(
        password.toUtf8(), 
        QCryptographicHash::Sha256).toHex());
}

bool Admin::validateInput()
{
    if (ui->loginEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите логин");
        return false;
    }
    
    if (!isEditMode && ui->passwordEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите пароль");
        return false;
    }
    
    if (ui->activationEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите код активации");
        return false;
    }
    
    return true;
}

void Admin::saveEmployeeData() {
    // Получаем данные из полей ввода
    QString fullName = fullNameEdit->text();
    QString position = positionEdit->text();
    QString otdel = otdelEdit->text();
    QString organization = organizationEdit->text();
    QString username = ui->userComboBox->currentText(); // Получаем логин пользователя

    // Проверка на пустые поля
    if (fullName.isEmpty() || position.isEmpty() || otdel.isEmpty() || organization.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, заполните все поля.");
        return;
    }

    QSqlQuery query(db);

    // Подготовка SQL-запроса для вставки данных
    if (isEditMode) {
    query.prepare("UPDATE Employees SET fullName = :fullName, position = :position, otdel = :otdel, organization = :organization WHERE username = :username");
    query.bindValue(":fullName", fullName);
    query.bindValue(":position", position);
    query.bindValue(":otdel", otdel);
    query.bindValue(":organization", organization);
    query.bindValue(":username", username);
    } else {
        // Если добавляете нового сотрудника
        query.prepare("INSERT INTO Employees (fullName, position, otdel, organization, username) VALUES (:fullName, :position, :otdel, :organization, :username)");
        query.bindValue(":fullName", fullName);
        query.bindValue(":position", position);
        query.bindValue(":otdel", otdel);
        query.bindValue(":organization", organization);
        query.bindValue(":username", username);
    }
    // Выполнение запроса
    if (query.exec()) {
        QMessageBox::information(this, "Успех", "Данные о сотруднике успешно сохранены.");
    } else {
        qDebug() << "Ошибка при сохранении данных о сотруднике:" << query.lastError().text();
        QMessageBox::critical(this, "Ошибка", "Не удалось сохранить данные: " + query.lastError().text());
    }
}
