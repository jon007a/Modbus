/********************************************************************************
** Form generated from reading UI file 'statistic.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTIC_H
#define UI_STATISTIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Statistic
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *userComboBox;
    QLabel *label_2;
    QLineEdit *passwordLineEdit;
    QPushButton *selectUserButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Statistic)
    {
        if (Statistic->objectName().isEmpty())
            Statistic->setObjectName("Statistic");
        Statistic->resize(200, 216);
        Statistic->setMinimumSize(QSize(200, 216));
        Statistic->setMaximumSize(QSize(200, 216));
        centralwidget = new QWidget(Statistic);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        userComboBox = new QComboBox(centralwidget);
        userComboBox->setObjectName("userComboBox");
        userComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #EFEFEF;\n"
"    color: #404040;\n"
"    border: 1px solid #C2C2C2;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    min-height: 20px;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    background-color: #E5E5E5;\n"
"    border: 1px solid #A0A0A0;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 1px solid #808080;\n"
"    background-color: #FAFAFA;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: center right;\n"
"    width: 22px;\n"
"    border-left: none;\n"
"    margin-right: 6px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(resources/arrow-down.png);\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}"));

        verticalLayout->addWidget(userComboBox);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        passwordLineEdit = new QLineEdit(centralwidget);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setMinimumSize(QSize(20, 32));
        passwordLineEdit->setMaximumSize(QSize(380, 30));
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

        verticalLayout->addWidget(passwordLineEdit);

        selectUserButton = new QPushButton(centralwidget);
        selectUserButton->setObjectName("selectUserButton");
        selectUserButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: center;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 5px 10px;\n"
"    font-weight: bold;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, \n"
"                              stop:0 #3A3A3A, stop:0.5 #606060, stop:1 #3A3A3A);\n"
"    border: none;\n"
"    min-height: 25px;\n"
"    max-width: 150px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, \n"
"                              stop:0 #2A2A2A, stop:0.5 #404040, stop:1 #2A2A2A) /* \320\242\320\265\320\274\320\275\320\265\320\265 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, \n"
"                              stop:0 #1F1F1F, stop:0.5 #303030, stop:1 #1F1F1F);\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background: #9E9E9E;\n"
"    color: #E0E0E0;\n"
"}"));

        verticalLayout->addWidget(selectUserButton);

        Statistic->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Statistic);
        statusbar->setObjectName("statusbar");
        Statistic->setStatusBar(statusbar);

        retranslateUi(Statistic);

        QMetaObject::connectSlotsByName(Statistic);
    } // setupUi

    void retranslateUi(QMainWindow *Statistic)
    {
        Statistic->setWindowTitle(QCoreApplication::translate("Statistic", "\320\222\321\213\320\261\320\276\321\200 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        label->setText(QCoreApplication::translate("Statistic", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("Statistic", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        selectUserButton->setText(QCoreApplication::translate("Statistic", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Statistic: public Ui_Statistic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTIC_H
