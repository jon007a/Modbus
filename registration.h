#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <QSqlDatabase>
#include <QRegularExpression>


namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

private slots:
    void onPasswordTextChanged();  // Слот для проверки совпадения паролей
    void onRegisterClicked();      // Слот для кнопки регистрации

private:
    Ui::Registration *ui;
    QSqlDatabase db;

    bool validateInput();          // Проверка всех полей
    bool validateActivationCode(const QString &code);  // Проверка кода активации
    QString hashPassword(const QString &password);     // Хеширование пароля
    bool initDatabase();           // Инициализация подключения к БД
    QString generateConnectionName();  // Генерация уникального имени подключения

    // Добавим новые методы валидации
    bool validateUsername(const QString &username);
    bool validatePassword(const QString &password);
    QRegularExpression usernameRegex;
    QRegularExpression passwordRegex;
    
    // Константы для валидации
    const int MIN_USERNAME_LENGTH = 3;
    const int MAX_USERNAME_LENGTH = 20;
    const int MIN_PASSWORD_LENGTH = 6;
    const int MAX_PASSWORD_LENGTH = 40;

    // Добавим новые методы валидации
    QString sanitizeInput(const QString &input);
    bool isValidInput(const QString &input);
};

#endif // REGISTRATION_H
