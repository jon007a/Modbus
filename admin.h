#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include <QSqlDatabase>
#include <QLineEdit>

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void loadUsers();
    void onUserSelected(const QString &username);
    void onAddClicked();
    void onEditClicked();
    void onDeleteClicked();
    void onSaveClicked();
    void onCancelClicked();
    
private:
    Ui::Admin *ui;
    QSqlDatabase db;
    bool isEditMode;

    QLineEdit *fullNameEdit;

    QLineEdit *positionEdit;

    QLineEdit *otdelEdit;

    QLineEdit *organizationEdit;
    
    void initDatabase();
    void updateUserData(const QString &username);
    void clearForm();
    void setFormEnabled(bool enabled);
    QString hashPassword(const QString &password);
    bool validateInput();
    void saveEmployeeData();
};

#endif // ADMIN_H
