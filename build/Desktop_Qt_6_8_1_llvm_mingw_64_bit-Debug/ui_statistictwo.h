/********************************************************************************
** Form generated from reading UI file 'statistictwo.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_statistictwo
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCustomPlot *customPlot;
    QCustomPlot *customPlot4;
    QCustomPlot *customPlot3;
    QCustomPlot *customPlot2;
    QPushButton *autoFollowButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *statistictwo)
    {
        if (statistictwo->objectName().isEmpty())
            statistictwo->setObjectName("statistictwo");
        statistictwo->resize(800, 600);
        statistictwo->setMinimumSize(QSize(800, 600));
        statistictwo->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(statistictwo);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName("customPlot");

        gridLayout->addWidget(customPlot, 1, 0, 1, 1);

        customPlot4 = new QCustomPlot(centralwidget);
        customPlot4->setObjectName("customPlot4");

        gridLayout->addWidget(customPlot4, 2, 1, 1, 1);

        customPlot3 = new QCustomPlot(centralwidget);
        customPlot3->setObjectName("customPlot3");

        gridLayout->addWidget(customPlot3, 2, 0, 1, 1);

        customPlot2 = new QCustomPlot(centralwidget);
        customPlot2->setObjectName("customPlot2");

        gridLayout->addWidget(customPlot2, 1, 1, 1, 1);

        autoFollowButton = new QPushButton(centralwidget);
        autoFollowButton->setObjectName("autoFollowButton");
        autoFollowButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D2D2D;\n"
"    color: #00FF00;  /* \320\227\320\265\320\273\320\265\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 \320\264\320\273\321\217 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\321\217 \"\320\222\320\272\320\273\" */\n"
"    border: 1px solid #3E3E3E;\n"
"    padding: 5px;\n"
"    min-width: 150px;\n"
"    min-height: 30px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #3E3E3E;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1E1E1E;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    color: #FF0000;  /* \320\232\321\200\320\260\321\201\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 \320\264\320\273\321\217 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\321\217 \"\320\222\321\213\320\272\320\273\" */\n"
"    background-color: #2D2D2D;\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #3E3E3E;\n"
"}"));

        gridLayout->addWidget(autoFollowButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D2D2D;\n"
"    color: #00FF00;  /* \320\227\320\265\320\273\320\265\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 \320\264\320\273\321\217 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\321\217 \"\320\222\320\272\320\273\" */\n"
"    border: 1px solid #3E3E3E;\n"
"    padding: 5px;\n"
"    min-width: 150px;\n"
"    min-height: 30px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #3E3E3E;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1E1E1E;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    color: #FF0000;  /* \320\232\321\200\320\260\321\201\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 \320\264\320\273\321\217 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\321\217 \"\320\222\321\213\320\272\320\273\" */\n"
"    background-color: #2D2D2D;\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #3E3E3E;\n"
"}"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        statistictwo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(statistictwo);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        autoFollowButton->setText(QCoreApplication::translate("statistictwo", "\320\220\320\262\321\202\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\320\275\320\270\320\265 \320\222\320\232\320\233/\320\222\320\253\320\232\320\233", nullptr));
        pushButton_2->setText(QCoreApplication::translate("statistictwo", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\276\321\202\321\207\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class statistictwo: public Ui_statistictwo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICTWO_H
