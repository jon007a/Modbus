/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionrtu;
    QAction *action;
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *qmlWidget;
    QProgressBar *progressBar1;
    QProgressBar *progressBar22;
    QPushButton *pushButton;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuStatistic;
    QMenu *menuConnection_type;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(799, 408);
        actionrtu = new QAction(MainWindow);
        actionrtu->setObjectName("actionrtu");
        action = new QAction(MainWindow);
        action->setObjectName("action");
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
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(progressBar22->sizePolicy().hasHeightForWidth());
        progressBar22->setSizePolicy(sizePolicy);
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
        progressBar22->setValue(24);
        progressBar22->setOrientation(Qt::Orientation::Horizontal);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(530, 270, 181, 41));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setEnabled(true);
        statusbar->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 799, 21));
        menuStatistic = new QMenu(menubar);
        menuStatistic->setObjectName("menuStatistic");
        menuConnection_type = new QMenu(menubar);
        menuConnection_type->setObjectName("menuConnection_type");
        menuConnection_type->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuStatistic->menuAction());
        menubar->addAction(menuConnection_type->menuAction());
        menuStatistic->addSeparator();
        menuStatistic->addAction(action);
        menuConnection_type->addSeparator();
        menuConnection_type->addAction(actionrtu);

        retranslateUi(MainWindow);
        QObject::connect(menubar, &QMenuBar::triggered, MainWindow, qOverload<>(&QMainWindow::show));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionrtu->setText(QCoreApplication::translate("MainWindow", "\320\262\320\260\321\200\320\270\320\260\320\275\321\202 \320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217", nullptr));
#if QT_CONFIG(tooltip)
        actionrtu->setToolTip(QCoreApplication::translate("MainWindow", "\320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217", nullptr));
#endif // QT_CONFIG(tooltip)
        action->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\276\320\272\320\275\320\276 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\270", nullptr));
        progressBar1->setFormat(QCoreApplication::translate("MainWindow", "%v Amp", nullptr));
        progressBar22->setFormat(QCoreApplication::translate("MainWindow", "%v Temp", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "but", nullptr));
        menuStatistic->setTitle(QCoreApplication::translate("MainWindow", "Statistic", nullptr));
        menuConnection_type->setTitle(QCoreApplication::translate("MainWindow", "Connection type", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
