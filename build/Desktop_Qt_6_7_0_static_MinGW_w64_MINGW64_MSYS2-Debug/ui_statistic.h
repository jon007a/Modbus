/********************************************************************************
** Form generated from reading UI file 'statistic.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTIC_H
#define UI_STATISTIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Statistic
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Statistic)
    {
        if (Statistic->objectName().isEmpty())
            Statistic->setObjectName("Statistic");
        Statistic->resize(800, 600);
        centralwidget = new QWidget(Statistic);
        centralwidget->setObjectName("centralwidget");
        Statistic->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Statistic);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Statistic->setMenuBar(menubar);
        statusbar = new QStatusBar(Statistic);
        statusbar->setObjectName("statusbar");
        Statistic->setStatusBar(statusbar);

        retranslateUi(Statistic);

        QMetaObject::connectSlotsByName(Statistic);
    } // setupUi

    void retranslateUi(QMainWindow *Statistic)
    {
        Statistic->setWindowTitle(QCoreApplication::translate("Statistic", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Statistic: public Ui_Statistic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTIC_H
