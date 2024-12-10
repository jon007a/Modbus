/********************************************************************************
** Form generated from reading UI file 'statistictwo.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICTWO_H
#define UI_STATISTICTWO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_statistictwo
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCustomPlot *customPlot2;
    QCustomPlot *customPlot;
    QCustomPlot *customPlot3;
    QCustomPlot *customPlot4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *statistictwo)
    {
        if (statistictwo->objectName().isEmpty())
            statistictwo->setObjectName("statistictwo");
        statistictwo->resize(800, 600);
        centralwidget = new QWidget(statistictwo);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        customPlot2 = new QCustomPlot(centralwidget);
        customPlot2->setObjectName("customPlot2");

        gridLayout->addWidget(customPlot2, 0, 1, 1, 1);

        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName("customPlot");

        gridLayout->addWidget(customPlot, 0, 0, 1, 1);

        customPlot3 = new QCustomPlot(centralwidget);
        customPlot3->setObjectName("customPlot3");

        gridLayout->addWidget(customPlot3, 1, 0, 1, 1);

        customPlot4 = new QCustomPlot(centralwidget);
        customPlot4->setObjectName("customPlot4");

        gridLayout->addWidget(customPlot4, 1, 1, 1, 1);

        statistictwo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(statistictwo);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        statistictwo->setMenuBar(menubar);
        statusbar = new QStatusBar(statistictwo);
        statusbar->setObjectName("statusbar");
        statistictwo->setStatusBar(statusbar);

        retranslateUi(statistictwo);

        QMetaObject::connectSlotsByName(statistictwo);
    } // setupUi

    void retranslateUi(QMainWindow *statistictwo)
    {
        statistictwo->setWindowTitle(QCoreApplication::translate("statistictwo", "\320\223\321\200\320\260\321\204\320\270\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class statistictwo: public Ui_statistictwo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICTWO_H
