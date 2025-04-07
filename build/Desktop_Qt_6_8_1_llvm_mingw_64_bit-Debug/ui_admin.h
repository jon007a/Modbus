/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *userComboBox;
    QGroupBox *editGroupBox;
    QFormLayout *formLayout;
    QLabel *loginLabel;
    QLineEdit *loginEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QLabel *activationLabel;
    QLineEdit *activationEdit;
    QLabel *fullNameLabel;
    QLineEdit *fullNameEdit;
    QLabel *positionLabel;
    QLineEdit *positionEdit;
    QLabel *label_2;
    QLineEdit *otdelEdit;
    QLabel *label_3;
    QLineEdit *organizationEdit;
    QComboBox *roleComboBox;
    QLabel *roleLabel;
    QHBoxLayout *buttonLayout;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *save2Button;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName("Admin");
        Admin->resize(800, 600);
        verticalLayout = new QVBoxLayout(Admin);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(Admin);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        userComboBox = new QComboBox(Admin);
        userComboBox->setObjectName("userComboBox");
        userComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #F5F5F5; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 */\n"
"    color: #333333; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: 1px solid #BBBBBB; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"    border-radius: 5px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"    min-height: 20px; /* \320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\321\213\321\201\320\276\321\202\320\260 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321"
                        "\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 1px solid #707070; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 \320\277\321\200\320\270 \321\204\320\276\320\272\321\203\321\201\320\265 */\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #F5F5F5; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"    color: #333333; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\262 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\274 \321\201\320\277\320\270\321\201\320\272\320\265 */\n"
"    selection-background-color: #A0A0A0; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\262\321\213\320\261\321\200\320\260\320\275\320"
                        "\275\320\276\320\263\320\276 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 */\n"
"    selection-color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 */\n"
"}"));

        horizontalLayout->addWidget(userComboBox);


        verticalLayout->addLayout(horizontalLayout);

        editGroupBox = new QGroupBox(Admin);
        editGroupBox->setObjectName("editGroupBox");
        formLayout = new QFormLayout(editGroupBox);
        formLayout->setObjectName("formLayout");
        loginLabel = new QLabel(editGroupBox);
        loginLabel->setObjectName("loginLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, loginLabel);

        loginEdit = new QLineEdit(editGroupBox);
        loginEdit->setObjectName("loginEdit");
        loginEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout->setWidget(0, QFormLayout::FieldRole, loginEdit);

        passwordLabel = new QLabel(editGroupBox);
        passwordLabel->setObjectName("passwordLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, passwordLabel);

        passwordEdit = new QLineEdit(editGroupBox);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordEdit);

        activationLabel = new QLabel(editGroupBox);
        activationLabel->setObjectName("activationLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, activationLabel);

        activationEdit = new QLineEdit(editGroupBox);
        activationEdit->setObjectName("activationEdit");
        activationEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout->setWidget(3, QFormLayout::FieldRole, activationEdit);

        fullNameLabel = new QLabel(editGroupBox);
        fullNameLabel->setObjectName("fullNameLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, fullNameLabel);

        fullNameEdit = new QLineEdit(editGroupBox);
        fullNameEdit->setObjectName("fullNameEdit");
        fullNameEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout->setWidget(4, QFormLayout::FieldRole, fullNameEdit);

        positionLabel = new QLabel(editGroupBox);
        positionLabel->setObjectName("positionLabel");

        formLayout->setWidget(5, QFormLayout::LabelRole, positionLabel);

        positionEdit = new QLineEdit(editGroupBox);
        positionEdit->setObjectName("positionEdit");
        positionEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout->setWidget(5, QFormLayout::FieldRole, positionEdit);

        label_2 = new QLabel(editGroupBox);
        label_2->setObjectName("label_2");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_2);

        otdelEdit = new QLineEdit(editGroupBox);
        otdelEdit->setObjectName("otdelEdit");
        otdelEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout->setWidget(6, QFormLayout::FieldRole, otdelEdit);

        label_3 = new QLabel(editGroupBox);
        label_3->setObjectName("label_3");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_3);

        organizationEdit = new QLineEdit(editGroupBox);
        organizationEdit->setObjectName("organizationEdit");
        organizationEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout->setWidget(7, QFormLayout::FieldRole, organizationEdit);

        roleComboBox = new QComboBox(editGroupBox);
        roleComboBox->addItem(QString());
        roleComboBox->addItem(QString());
        roleComboBox->addItem(QString());
        roleComboBox->setObjectName("roleComboBox");
        roleComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #F5F5F5; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 */\n"
"    color: #333333; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: 1px solid #BBBBBB; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"    border-radius: 5px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"    min-height: 20px; /* \320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\321\213\321\201\320\276\321\202\320\260 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321"
                        "\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 1px solid #707070; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 \320\277\321\200\320\270 \321\204\320\276\320\272\321\203\321\201\320\265 */\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #F5F5F5; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"    color: #333333; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\262 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\274 \321\201\320\277\320\270\321\201\320\272\320\265 */\n"
"    selection-background-color: #A0A0A0; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\262\321\213\320\261\321\200\320\260\320\275\320"
                        "\275\320\276\320\263\320\276 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 */\n"
"    selection-color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 */\n"
"}"));

        formLayout->setWidget(2, QFormLayout::FieldRole, roleComboBox);

        roleLabel = new QLabel(editGroupBox);
        roleLabel->setObjectName("roleLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, roleLabel);


        verticalLayout->addWidget(editGroupBox);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        addButton = new QPushButton(Admin);
        addButton->setObjectName("addButton");
        addButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F5F5F5; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 */\n"
"    color: #333333; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: 1px solid #BBBBBB; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"    border-radius: 5px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    min-height: 20px; /* \320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\321\213\321\201\320\276\321\202\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    border: 1px solid #707070; /* \320\246\320\262\320\265"
                        "\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 \320\277\321\200\320\270 \321\204\320\276\320\272\321\203\321\201\320\265 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #E0E0E0; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #D0D0D0; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"}"));

        buttonLayout->addWidget(addButton);

        editButton = new QPushButton(Admin);
        editButton->setObjectName("editButton");
        editButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F5F5F5; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 */\n"
"    color: #333333; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: 1px solid #BBBBBB; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"    border-radius: 5px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    min-height: 20px; /* \320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\321\213\321\201\320\276\321\202\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    border: 1px solid #707070; /* \320\246\320\262\320\265"
                        "\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 \320\277\321\200\320\270 \321\204\320\276\320\272\321\203\321\201\320\265 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #E0E0E0; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #D0D0D0; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"}"));

        buttonLayout->addWidget(editButton);

        deleteButton = new QPushButton(Admin);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F5F5F5; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 */\n"
"    color: #333333; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: 1px solid #BBBBBB; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"    border-radius: 5px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    min-height: 20px; /* \320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\321\213\321\201\320\276\321\202\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    border: 1px solid #707070; /* \320\246\320\262\320\265"
                        "\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 \320\277\321\200\320\270 \321\204\320\276\320\272\321\203\321\201\320\265 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #E0E0E0; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #D0D0D0; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"}"));

        buttonLayout->addWidget(deleteButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        save2Button = new QPushButton(Admin);
        save2Button->setObjectName("save2Button");

        buttonLayout->addWidget(save2Button);

        saveButton = new QPushButton(Admin);
        saveButton->setObjectName("saveButton");
        saveButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F5F5F5; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 */\n"
"    color: #333333; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: 1px solid #BBBBBB; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"    border-radius: 5px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    min-height: 20px; /* \320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\321\213\321\201\320\276\321\202\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    border: 1px solid #707070; /* \320\246\320\262\320\265"
                        "\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 \320\277\321\200\320\270 \321\204\320\276\320\272\321\203\321\201\320\265 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #E0E0E0; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #D0D0D0; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"}"));

        buttonLayout->addWidget(saveButton);

        cancelButton = new QPushButton(Admin);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F5F5F5; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 */\n"
"    color: #333333; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: 1px solid #BBBBBB; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"    border-radius: 5px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"    min-height: 20px; /* \320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\321\213\321\201\320\276\321\202\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    border: 1px solid #707070; /* \320\246\320\262\320\265"
                        "\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 \320\277\321\200\320\270 \321\204\320\276\320\272\321\203\321\201\320\265 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #E0E0E0; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #D0D0D0; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"}"));

        buttonLayout->addWidget(cancelButton);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(Admin);

        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QDialog *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "\320\237\320\260\320\275\320\265\320\273\321\214 \320\260\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("Admin", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217:", nullptr));
        editGroupBox->setTitle(QCoreApplication::translate("Admin", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        loginLabel->setText(QCoreApplication::translate("Admin", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        passwordLabel->setText(QCoreApplication::translate("Admin", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        activationLabel->setText(QCoreApplication::translate("Admin", "\320\232\320\276\320\264 \320\260\320\272\321\202\320\270\320\262\320\260\321\206\320\270\320\270:", nullptr));
        fullNameLabel->setText(QCoreApplication::translate("Admin", "\320\244\320\230\320\236:", nullptr));
        positionLabel->setText(QCoreApplication::translate("Admin", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214:", nullptr));
        label_2->setText(QCoreApplication::translate("Admin", "\320\236\321\202\320\264\320\265\320\273", nullptr));
        label_3->setText(QCoreApplication::translate("Admin", "\320\236\321\200\320\263\320\260\320\275\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        roleComboBox->setItemText(0, QCoreApplication::translate("Admin", "admin", nullptr));
        roleComboBox->setItemText(1, QCoreApplication::translate("Admin", "engineer", nullptr));
        roleComboBox->setItemText(2, QCoreApplication::translate("Admin", "operator", nullptr));

        roleLabel->setText(QCoreApplication::translate("Admin", "\320\240\320\276\320\273\321\214:", nullptr));
        addButton->setText(QCoreApplication::translate("Admin", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        editButton->setText(QCoreApplication::translate("Admin", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        deleteButton->setText(QCoreApplication::translate("Admin", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        save2Button->setText(QCoreApplication::translate("Admin", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\204\320\270\320\276", nullptr));
        saveButton->setText(QCoreApplication::translate("Admin", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        cancelButton->setText(QCoreApplication::translate("Admin", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
