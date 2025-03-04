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
    QComboBox *userComboBox;
    QLineEdit *passwordLineEdit;
    QPushButton *selectUserButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Statistic)
    {
        if (Statistic->objectName().isEmpty())
            Statistic->setObjectName("Statistic");
        Statistic->resize(400, 300);
        Statistic->setMinimumSize(QSize(400, 300));
        Statistic->setMaximumSize(QSize(402, 300));
        centralwidget = new QWidget(Statistic);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        userComboBox = new QComboBox(centralwidget);
        userComboBox->setObjectName("userComboBox");

        verticalLayout->addWidget(userComboBox);

        passwordLineEdit = new QLineEdit(centralwidget);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setMinimumSize(QSize(380, 30));
        passwordLineEdit->setMaximumSize(QSize(380, 30));

        verticalLayout->addWidget(passwordLineEdit);

        selectUserButton = new QPushButton(centralwidget);
        selectUserButton->setObjectName("selectUserButton");

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
        selectUserButton->setText(QCoreApplication::translate("Statistic", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Statistic: public Ui_Statistic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTIC_H
