/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionrtu;
    QAction *action;
    QAction *action_2;
    QAction *actionOpenManual;
    QAction *actionRegister1;
    QAction *actionRegister;
    QAction *actionExportReport;
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *qmlWidget;
    QProgressBar *progressBar1;
    QProgressBar *progressBar22;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *resetButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *statusLabel;
    QPushButton *disconnectButton;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuStatistic;
    QMenu *menuConnection_type;
    QMenu *menustatistictwo;
    QMenu *menuModbusManual;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 420);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 420));
        MainWindow->setMaximumSize(QSize(800, 420));
        actionrtu = new QAction(MainWindow);
        actionrtu->setObjectName("actionrtu");
        action = new QAction(MainWindow);
        action->setObjectName("action");
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        actionOpenManual = new QAction(MainWindow);
        actionOpenManual->setObjectName("actionOpenManual");
        actionRegister1 = new QAction(MainWindow);
        actionRegister1->setObjectName("actionRegister1");
        actionRegister = new QAction(MainWindow);
        actionRegister->setObjectName("actionRegister");
        actionExportReport = new QAction(MainWindow);
        actionExportReport->setObjectName("actionExportReport");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 301, 301));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        qmlWidget = new QWidget(horizontalLayoutWidget);
        qmlWidget->setObjectName("qmlWidget");

        horizontalLayout->addWidget(qmlWidget);

        progressBar1 = new QProgressBar(centralwidget);
        progressBar1->setObjectName("progressBar1");
        progressBar1->setGeometry(QRect(320, 40, 451, 31));
        progressBar1->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    background-color: #f0f0f0;               /* \320\241\320\262\320\265\321\202\320\273\321\213\320\271 \321\204\320\276\320\275 */\n"
"    border: 1px solid #696969;               /* \320\241\320\262\320\265\321\202\320\273\320\276-\321\201\320\265\321\200\320\260\321\217 \320\263\321\200\320\260\320\275\320\270\321\206\320\260 */\n"
"    border-radius: 10px;                     /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \320\272\321\200\320\260\321\217 */\n"
"    text-align: center;                      /* \320\246\320\265\320\275\321\202\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    font-size: 12px;                         /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"    color: #555555;                          /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\206\320\262\320\265"
                        "\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    min-height: 25px;                        /* \320\222\321\213\321\201\320\276\321\202\320\260 \320\277\321\200\320\276\320\263\321\200\320\265\321\201\321\201-\320\261\320\260\321\200\320\260 */\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: qlineargradient(\n"
"        spread:pad, x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d0d0d0, stop:1 #696969);     /* \320\234\320\260\321\202\320\276\320\262\321\213\320\271 \321\201\320\265\321\200\321\213\320\271 \320\263\321\200\320\260\320\264\320\270\320\265\320\275\321\202 */\n"
"    border-radius: 8px;                      /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \320\272\321\200\320\260\321\217 \321\201\320\265\320\263\320\274\320\265\320\275\321\202\320\260 */\n"
"    margin: 2px;                             /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\276\321\202 \320\272\321\200\320\260\320\265\320\262"
                        " */\n"
"}\n"
""));
        progressBar1->setValue(24);
        progressBar1->setOrientation(Qt::Orientation::Horizontal);
        progressBar22 = new QProgressBar(centralwidget);
        progressBar22->setObjectName("progressBar22");
        progressBar22->setGeometry(QRect(320, 90, 451, 31));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(progressBar22->sizePolicy().hasHeightForWidth());
        progressBar22->setSizePolicy(sizePolicy1);
        progressBar22->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    background-color: #f0f0f0;               /* \320\241\320\262\320\265\321\202\320\273\321\213\320\271 \321\204\320\276\320\275 */\n"
"    border: 1px solid #696969;               /* \320\241\320\262\320\265\321\202\320\273\320\276-\321\201\320\265\321\200\320\260\321\217 \320\263\321\200\320\260\320\275\320\270\321\206\320\260 */\n"
"    border-radius: 10px;                     /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \320\272\321\200\320\260\321\217 */\n"
"    text-align: center;                      /* \320\246\320\265\320\275\321\202\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    font-size: 12px;                         /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"    color: #555555;                          /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\206\320\262\320\265"
                        "\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    min-height: 25px;                        /* \320\222\321\213\321\201\320\276\321\202\320\260 \320\277\321\200\320\276\320\263\321\200\320\265\321\201\321\201-\320\261\320\260\321\200\320\260 */\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: qlineargradient(\n"
"        spread:pad, x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d0d0d0, stop:1 #696969);     /* \320\234\320\260\321\202\320\276\320\262\321\213\320\271 \321\201\320\265\321\200\321\213\320\271 \320\263\321\200\320\260\320\264\320\270\320\265\320\275\321\202 */\n"
"    border-radius: 8px;                      /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \320\272\321\200\320\260\321\217 \321\201\320\265\320\263\320\274\320\265\320\275\321\202\320\260 */\n"
"    margin: 2px;                             /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\276\321\202 \320\272\321\200\320\260\320\265\320\262"
                        " */\n"
"}\n"
""));
        progressBar22->setMaximum(800);
        progressBar22->setValue(24);
        progressBar22->setOrientation(Qt::Orientation::Horizontal);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(330, 130, 296, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        startButton = new QPushButton(verticalLayoutWidget);
        startButton->setObjectName("startButton");
        startButton->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"       background-color: #2D2D2D; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 */\n"
"       color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216 */\n"
"       border: 1px solid #3E3E3E;\n"
"       padding: 5px;\n"
"   }\n"
"   QPushButton:hover {\n"
"       background-color: #3E3E3E; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"   }"));
        startButton->setCheckable(false);

        horizontalLayout_2->addWidget(startButton);

        stopButton = new QPushButton(verticalLayoutWidget);
        stopButton->setObjectName("stopButton");
        stopButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"       background-color: #2D2D2D; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 */\n"
"       color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216 */\n"
"       border: 1px solid #3E3E3E;\n"
"       padding: 5px;\n"
"   }\n"
"   QPushButton:hover {\n"
"       background-color: #3E3E3E; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"   }"));
        stopButton->setCheckable(false);

        horizontalLayout_2->addWidget(stopButton);

        resetButton = new QPushButton(verticalLayoutWidget);
        resetButton->setObjectName("resetButton");
        resetButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"       background-color: #2D2D2D; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 */\n"
"       color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216 */\n"
"       border: 1px solid #3E3E3E;\n"
"       padding: 5px;\n"
"   }\n"
"   QPushButton:hover {\n"
"       background-color: #3E3E3E; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"   }"));

        horizontalLayout_2->addWidget(resetButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        statusLabel = new QLabel(verticalLayoutWidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #2D2D2D;\n"
"    color: #FFFFFF;\n"
"    border: 1px solid #3E3E3E;\n"
"    padding: 5px;\n"
"    min-width: 100px;\n"
"    font-weight: bold;\n"
"    border-radius: 3px;\n"
"}"));

        horizontalLayout_4->addWidget(statusLabel);


        verticalLayout->addLayout(horizontalLayout_4);

        disconnectButton = new QPushButton(centralwidget);
        disconnectButton->setObjectName("disconnectButton");
        disconnectButton->setGeometry(QRect(690, 290, 93, 29));
        disconnectButton->setStyleSheet(QString::fromUtf8("\n"
"    QPushButton {\n"
"        background-color: #2D2D2D;\n"
"        color: #FF0000;\n"
"        border: 1px solid #3E3E3E;\n"
"        padding: 5px;\n"
"        min-width: 80px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #3E3E3E;\n"
"    }\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setEnabled(true);
        statusbar->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 33));
        menubar->setStyleSheet(QString::fromUtf8("QMenuBar {\n"
"    background-color: #1E1E1E;\n"
"    color: #D4D4D4;\n"
"    border-bottom: 1px solid #2D2D2D;\n"
"}\n"
"QMenuBar::item {\n"
"    padding: 8px 12px;\n"
"    background: transparent;\n"
"}\n"
"QMenuBar::item:selected {\n"
"    background-color: #2D2D2D;\n"
"    border-radius: 4px;\n"
"}\n"
"QMenuBar::item:pressed {\n"
"    background-color: #3D3D3D;\n"
"}\n"
"QMenu {\n"
"    background-color: #1E1E1E;\n"
"    color: #D4D4D4;\n"
"    border: 1px solid #2D2D2D;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"    margin: 2px;\n"
"}\n"
"QMenu::item {\n"
"    padding: 8px 25px 8px 20px;\n"
"    border-radius: 4px;\n"
"}\n"
"QMenu::item:selected {\n"
"    background-color: #2D2D2D;\n"
"}\n"
"QMenu::item:pressed {\n"
"    background-color: #3D3D3D;\n"
"}\n"
"QMenu::separator {\n"
"    height: 1px;\n"
"    background: #2D2D2D;\n"
"    margin: 5px 10px;\n"
"}\n"
"QMenu::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"}"));
        menuStatistic = new QMenu(menubar);
        menuStatistic->setObjectName("menuStatistic");
        menuConnection_type = new QMenu(menubar);
        menuConnection_type->setObjectName("menuConnection_type");
        menuConnection_type->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        menustatistictwo = new QMenu(menubar);
        menustatistictwo->setObjectName("menustatistictwo");
        menuModbusManual = new QMenu(menubar);
        menuModbusManual->setObjectName("menuModbusManual");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuStatistic->menuAction());
        menubar->addAction(menuConnection_type->menuAction());
        menubar->addAction(menustatistictwo->menuAction());
        menubar->addAction(menuModbusManual->menuAction());
        menuStatistic->addSeparator();
        menuStatistic->addAction(action);
        menuStatistic->addAction(actionRegister);
        menuConnection_type->addSeparator();
        menuConnection_type->addAction(actionrtu);
        menustatistictwo->addAction(action_2);
        menuModbusManual->addAction(actionOpenManual);

        retranslateUi(MainWindow);
        QObject::connect(menubar, &QMenuBar::triggered, MainWindow, qOverload<>(&QMainWindow::show));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionrtu->setText(QCoreApplication::translate("MainWindow", "\320\262\320\260\321\200\320\270\320\260\320\275\321\202 \320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217", nullptr));
#if QT_CONFIG(tooltip)
        actionrtu->setToolTip(QCoreApplication::translate("MainWindow", "\320\262\320\260\321\200\320\270\320\260\320\275\321\202 \320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217", nullptr));
#endif // QT_CONFIG(tooltip)
        action->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
        actionOpenManual->setText(QCoreApplication::translate("MainWindow", "Open Manual", nullptr));
        actionRegister1->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\276\320\272\320\275\320\276 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270", nullptr));
        actionRegister->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        actionExportReport->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\201\321\202\320\260\320\262\320\270\321\202\321\214 \320\276\321\202\321\207\320\265\321\202", nullptr));
        progressBar1->setFormat(QCoreApplication::translate("MainWindow", "%v Amp", nullptr));
        progressBar22->setFormat(QCoreApplication::translate("MainWindow", "%v Volt", nullptr));
#if QT_CONFIG(tooltip)
        startButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\320\272 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
        startButton->setText(QCoreApplication::translate("MainWindow", "\320\237\321\203\321\201\320\272", nullptr));
#if QT_CONFIG(tooltip)
        stopButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276", nullptr));
#endif // QT_CONFIG(tooltip)
        stopButton->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\276\320\277", nullptr));
#if QT_CONFIG(tooltip)
        resetButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201 \320\276\321\210\320\270\320\261\320\276\320\272", nullptr));
#endif // QT_CONFIG(tooltip)
        resetButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        statusLabel->setText(QString());
        disconnectButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\253\320\245\320\236\320\224", nullptr));
        menuStatistic->setTitle(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        menuConnection_type->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217", nullptr));
        menustatistictwo->setTitle(QCoreApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272\320\270", nullptr));
        menuModbusManual->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\275\321\203\320\260\320\273 \320\277\320\276 \320\277\321\200\320\276\321\202\320\276\320\272\320\276\320\273\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
