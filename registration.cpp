#include "registration.h"
#include "ui_registration.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include <QDebug>
#include <QRegularExpression>

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("C:/Qt/Raboti/vfd/pictures/registry.png"));

    // Инициализация регулярных выражений
    usernameRegex = QRegularExpression("^[a-zA-Z0-9_-]{3,20}$");
    passwordRegex = QRegularExpression("^(?=.*[A-Za-z])(?=.*\\d)[A-Za-z\\d@$!%*#?&]{6,}$");

    // Добавляем валидаторы для полей ввода
    ui->usernameLineEdit->setMaxLength(MAX_USERNAME_LENGTH);
    ui->passwordLineEdit->setMaxLength(MAX_PASSWORD_LENGTH);
    ui->confirmPasswordLineEdit->setMaxLength(MAX_PASSWORD_LENGTH);
    
    // Подключаем сигналы для валидации в реальном времени
    connect(ui->usernameLineEdit, &QLineEdit::textChanged, 
            this, [this](const QString &text) {
        if (!validateUsername(text)) {
            ui->usernameLineEdit->setStyleSheet("QLineEdit { border: 1px solid red; }");
            ui->usernameLabel->setText("Имя пользователя: (только буквы, цифры, _ и -)");
            ui->usernameLabel->setStyleSheet("QLabel { color: red; }");
        } else {
            ui->usernameLineEdit->setStyleSheet("");
            ui->usernameLabel->setText("Имя пользователя:");
            ui->usernameLabel->setStyleSheet("");
        }
    });

    // Инициализация БД
    if (!initDatabase()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось подключиться к базе данных");
        return;
    }

    // Подключаем сигналы
    connect(ui->passwordLineEdit, &QLineEdit::textChanged,
            this, &Registration::onPasswordTextChanged);
    connect(ui->confirmPasswordLineEdit, &QLineEdit::textChanged,
            this, &Registration::onPasswordTextChanged);
    connect(ui->registerButton, &QPushButton::clicked,
            this, &Registration::onRegisterClicked);

    // Изначально кнопка регистрации неактивна
    ui->registerButton->setEnabled(false);
}

Registration::~Registration()
{
    if (db.isOpen()) {
        db.close();
    }
    delete ui;
}

void Registration::onPasswordTextChanged()
{
    QString password = ui->passwordLineEdit->text();
    QString confirm = ui->confirmPasswordLineEdit->text();

    if (password.isEmpty() || confirm.isEmpty()) {
        ui->passwordMatchLabel->clear();
        ui->registerButton->setEnabled(false);
        return;
    }

    if (password == confirm) {
        ui->passwordMatchLabel->setText("Пароли совпадают");
        ui->passwordMatchLabel->setStyleSheet("color: green");
        ui->registerButton->setEnabled(true);
    } else {
        ui->passwordMatchLabel->setText("Пароли не совпадают");
        ui->passwordMatchLabel->setStyleSheet("color: red");
        ui->registerButton->setEnabled(false);
    }
}

bool Registration::validateActivationCode(const QString &code)
{
    QString upperCode = code.toUpper();
    return (upperCode == "ADMIN2024" ||
            upperCode == "ENGINEER2024" ||
            upperCode == "OPERATOR2024");
}

void Registration::onRegisterClicked()
{
    if (!validateInput()) {
        return;
    }

    // Очищаем входные данные
    QString username = sanitizeInput(ui->usernameLineEdit->text());
    QString password = ui->passwordLineEdit->text();
    QString activationCode = sanitizeInput(ui->activationCodeLineEdit->text().toUpper());

    // Определяем роль на основе кода активации
    QString role;
    if (activationCode == "ADMIN2024") {
        role = "admin";
    } else if (activationCode == "ENGINEER2024") {
        role = "engineer";
    } else if (activationCode == "OPERATOR2024") {
        role = "operator";
    } else {
        QMessageBox::warning(this, "Ошибка", "Неверный код активации");
        return;
    }

    // Проверка на специальные символы
    if (!isValidInput(username)) {
        QMessageBox::warning(this, "Ошибка", 
            "Имя пользователя содержит недопустимые символы");
        return;
    }



    // Вставка пользователя через prepared statement
    QSqlQuery insertQuery(db);
    insertQuery.prepare(
        "INSERT INTO users (username, created_at, password_hash, role, activation_code) "
        "VALUES (:username, CURRENT_TIMESTAMP, :password, :role, :activation_code)"
        );
    
    insertQuery.bindValue(":username", username);
    insertQuery.bindValue(":password", hashPassword(password));
    insertQuery.bindValue(":role", role);
    insertQuery.bindValue(":activation_code", activationCode);

    if (insertQuery.exec()) {
        qDebug() << "User registered successfully:"
                 << "\nUsername:" << username
                 << "\nRole:" << role
                 << "\nActivation code:" << activationCode;

        QMessageBox::information(this, "Успех", "Регистрация успешно завершена");
        accept();
    } else {
        // Логируем неудачную попытку
        QSqlQuery logQuery(db);
        logQuery.prepare(
            "INSERT INTO registration_log (username, ip_address, success, error_message) "
            "VALUES (:username, :ip, FALSE, :error)"
        );
        logQuery.bindValue(":username", username);
        logQuery.bindValue(":ip", "::1");
        logQuery.bindValue(":error", insertQuery.lastError().text());
        logQuery.exec();

        QMessageBox::critical(this, "Ошибка",
                          "Ошибка при регистрации: " + insertQuery.lastError().text());
    }
}

bool Registration::validateInput()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString confirmPassword = ui->confirmPasswordLineEdit->text();
    QString activationCode = ui->activationCodeLineEdit->text();

    // Проверка имени пользователя
    if (!validateUsername(username)) {
        QMessageBox::warning(this, "Ошибка", 
            "Некорректное имя пользователя.\n"
            "- Длина от 3 до 20 символов\n"
            "- Только буквы, цифры, _ и -\n"
            "- Не может быть зарезервированным словом");
        return false;
    }

    // Проверка пароля
    if (!validatePassword(password)) {
        QMessageBox::warning(this, "Ошибка",
            "Пароль не соответствует требованиям:\n"
            "- Минимум 6 символов\n"
            "- Должен содержать буквы и цифры\n"
            "- Специальные символы приветствуются");
        return false;
    }

    // Проверка совпадения паролей
    if (password != confirmPassword) {
        QMessageBox::warning(this, "Ошибка", "Пароли не совпадают");
        return false;
    }

    // Проверка кода активации
    if (!validateActivationCode(activationCode)) {
        QMessageBox::warning(this, "Ошибка", 
            "Неверный код активации.\n"
            "Обратитесь к администратору для получения кода.");
        return false;
    }

    // Проверка на существующего пользователя
    QSqlQuery query(db);
    query.prepare("SELECT username FROM users WHERE username = :username");
    query.bindValue(":username", username);
    
    if (query.exec() && query.next()) {
        QMessageBox::warning(this, "Ошибка", 
            "Пользователь с таким именем уже существует");
        return false;
    }

    return true;
}

bool Registration::validateUsername(const QString &username)
{
    // Проверка длины
    if (username.length() < MIN_USERNAME_LENGTH || 
        username.length() > MAX_USERNAME_LENGTH) {
        return false;
    }

    // Проверка на допустимые символы
    if (!usernameRegex.match(username).hasMatch()) {
        return false;
    }

    // Проверка на запрещенные слова
    QStringList forbiddenWords = {"admin", "root", "system", "administrator"};
    for (const QString &word : forbiddenWords) {
        if (username.toLower() == word) {
            return false;
        }
    }

    return true;
}

bool Registration::validatePassword(const QString &password)
{
    // Проверка длины
    if (password.length() < MIN_PASSWORD_LENGTH || 
        password.length() > MAX_PASSWORD_LENGTH) {
        return false;
    }

    // Проверка на сложность пароля
    bool hasLetter = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    for (QChar ch : password) {
        if (ch.isLetter()) hasLetter = true;
        if (ch.isDigit()) hasDigit = true;
        if (!ch.isLetterOrNumber()) hasSpecial = true;
    }

    return hasLetter && hasDigit; // Минимальные требования
}

QString Registration::hashPassword(const QString &password)
{
    return QString(QCryptographicHash::hash(
                       password.toUtf8(),
                       QCryptographicHash::Sha256).toHex());
}

bool Registration::initDatabase()
{
    db = QSqlDatabase::addDatabase("QPSQL", generateConnectionName());
    db.setHostName("localhost");
    db.setDatabaseName("statisticbase");
    db.setUserName("postgres");
    db.setPassword("1234");
    db.setPort(5432);

    return db.open();
}

QString Registration::generateConnectionName()
{
    static int counter = 0;
    return QString("Registration_Connection_%1").arg(++counter);
}

QString Registration::sanitizeInput(const QString &input)
{
    // Удаляем пробелы в начале и конце
    QString cleaned = input.trimmed();
    
    // Заменяем опасные символы
    cleaned.replace("'", "''");
    cleaned.replace(";", "");
    cleaned.replace("--", "");
    cleaned.replace("/*", "");
    cleaned.replace("*/", "");
    
    return cleaned;
}

bool Registration::isValidInput(const QString &input)
{
    // Проверка на допустимые символы
    QRegularExpression validChars("^[a-zA-Z0-9_-]+$");
    if (!validChars.match(input).hasMatch()) {
        return false;
    }
    
    // Проверка на SQL-инъекции
    QStringList sqlKeywords = {
        "SELECT", "INSERT", "UPDATE", "DELETE",
        "DROP", "UNION", "WHERE", "OR", "AND"
    };
    
    QString upperInput = input.toUpper();
    for (const QString &keyword : sqlKeywords) {
        if (upperInput.contains(keyword)) {
            return false;
        }
    }
    
    return true;
}
