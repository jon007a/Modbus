/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Registration
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *passwordMatchLabel;
    QLineEdit *confirmPasswordLineEdit;
    QLabel *passwordLabel;
    QLabel *confirmPasswordLabel;
    QLineEdit *activationCodeLineEdit;
    QLabel *activationCodeLabel;
    QLineEdit *passwordLineEdit;
    QLabel *usernameLabel;
    QLineEdit *usernameLineEdit;
    QLabel *label;
    QPushButton *registerButton;

    void setupUi(QDialog *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName("Registration");
        Registration->resize(650, 370);
        Registration->setMinimumSize(QSize(650, 370));
        Registration->setMaximumSize(QSize(650, 370));
        gridLayoutWidget = new QWidget(Registration);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 10, 626, 349));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        passwordMatchLabel = new QLabel(gridLayoutWidget);
        passwordMatchLabel->setObjectName("passwordMatchLabel");

        gridLayout->addWidget(passwordMatchLabel, 9, 0, 1, 1);

        confirmPasswordLineEdit = new QLineEdit(gridLayoutWidget);
        confirmPasswordLineEdit->setObjectName("confirmPasswordLineEdit");
        confirmPasswordLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #F5F5F5;\n"
"    color: #333333;\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #707070;\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #E0E0E0;\n"
"    color: #9E9E9E;\n"
"}"));
        confirmPasswordLineEdit->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout->addWidget(confirmPasswordLineEdit, 6, 0, 1, 1);

        passwordLabel = new QLabel(gridLayoutWidget);
        passwordLabel->setObjectName("passwordLabel");

        gridLayout->addWidget(passwordLabel, 3, 0, 1, 1);

        confirmPasswordLabel = new QLabel(gridLayoutWidget);
        confirmPasswordLabel->setObjectName("confirmPasswordLabel");

        gridLayout->addWidget(confirmPasswordLabel, 5, 0, 1, 1);

        activationCodeLineEdit = new QLineEdit(gridLayoutWidget);
        activationCodeLineEdit->setObjectName("activationCodeLineEdit");
        activationCodeLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #F5F5F5;\n"
"    color: #333333;\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #707070;\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #E0E0E0;\n"
"    color: #9E9E9E;\n"
"}"));
        activationCodeLineEdit->setMaxLength(12);

        gridLayout->addWidget(activationCodeLineEdit, 8, 0, 1, 1);

        activationCodeLabel = new QLabel(gridLayoutWidget);
        activationCodeLabel->setObjectName("activationCodeLabel");

        gridLayout->addWidget(activationCodeLabel, 7, 0, 1, 1);

        passwordLineEdit = new QLineEdit(gridLayoutWidget);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #F5F5F5;\n"
"    color: #333333;\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #707070;\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #E0E0E0;\n"
"    color: #9E9E9E;\n"
"}"));
        passwordLineEdit->setMaxLength(40);
        passwordLineEdit->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout->addWidget(passwordLineEdit, 4, 0, 1, 1);

        usernameLabel = new QLabel(gridLayoutWidget);
        usernameLabel->setObjectName("usernameLabel");

        gridLayout->addWidget(usernameLabel, 1, 0, 1, 1);

        usernameLineEdit = new QLineEdit(gridLayoutWidget);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #F5F5F5;\n"
"    color: #333333;\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #707070;\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #E0E0E0;\n"
"    color: #9E9E9E;\n"
"}"));
        usernameLineEdit->setMaxLength(20);

        gridLayout->addWidget(usernameLineEdit, 2, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");
        label->setEnabled(true);

        gridLayout->addWidget(label, 10, 0, 1, 1);

        registerButton = new QPushButton(gridLayoutWidget);
        registerButton->setObjectName("registerButton");
        registerButton->setEnabled(false);
        registerButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    padding: 8px 16px;\n"
"    background-color: #2D2D2D;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #3E3E3E;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #1E1E1E;\n"
"    color: #666666;\n"
"}QPushButton {\n"
"    padding: 8px 16px;\n"
"    background-color: #2D2D2D;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"}"));

        gridLayout->addWidget(registerButton, 10, 1, 1, 1);


        retranslateUi(Registration);

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QDialog *Registration)
    {
        Registration->setWindowTitle(QCoreApplication::translate("Registration", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        passwordMatchLabel->setText(QString());
        confirmPasswordLineEdit->setPlaceholderText(QCoreApplication::translate("Registration", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        passwordLabel->setText(QCoreApplication::translate("Registration", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        confirmPasswordLabel->setText(QCoreApplication::translate("Registration", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214:", nullptr));
        activationCodeLineEdit->setPlaceholderText(QCoreApplication::translate("Registration", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\264 \320\260\320\272\321\202\320\270\320\262\320\260\321\206\320\270\320\270", nullptr));
        activationCodeLabel->setText(QCoreApplication::translate("Registration", "\320\232\320\276\320\264 \320\260\320\272\321\202\320\270\320\262\320\260\321\206\320\270\320\270:", nullptr));
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("Registration", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        usernameLabel->setText(QCoreApplication::translate("Registration", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217:", nullptr));
        usernameLineEdit->setPlaceholderText(QCoreApplication::translate("Registration", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\273\320\276\320\263\320\270\320\275", nullptr));
        label->setText(QCoreApplication::translate("Registration", "\320\232\320\276\320\264 \320\260\320\272\321\202\320\270\320\262\320\260\321\206\320\270\320\270 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\274\320\276\320\266\320\275\320\276 \320\277\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\203 \320\260\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270", nullptr));
        registerButton->setText(QCoreApplication::translate("Registration", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
