#ifndef ERRORWINDOW_H
#define ERRORWINDOW_H

#include <QDialog>
#include <QTableWidget>
#include <QComboBox>
#include <QDateEdit>
#include <QtSql/QSqlDatabase>

namespace Ui {
class ErrorWindow; // Объявление класса UI
}

class ErrorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorWindow(int userId,QWidget *parent = nullptr);
    ~ErrorWindow();
    void saveErrorToDatabase(int userId, int errorCode, const QString &errorDescription); // Сохранение ошибки в БД

private slots:
    void loadUsers(); // Загрузка пользователей в comboBox
    void refreshErrorList(); // Обновление списка ошибок
    void exportErrors(); // Экспорт ошибок
    void filterErrorsByDate(); // Фильтрация ошибок по дате

private:
    Ui::ErrorWindow *ui; // Указатель на UI
    QSqlDatabase db; // Указатель на базу данных

    void initDatabase(); // Метод для инициализации базы данных
    int currentUserId;
};

#endif // ERRORWINDOW_H
