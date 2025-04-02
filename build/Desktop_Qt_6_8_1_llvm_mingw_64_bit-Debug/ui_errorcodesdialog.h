/********************************************************************************
** Form generated from reading UI file 'errorcodesdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORCODESDIALOG_H
#define UI_ERRORCODESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_errorcodesdialog
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *errorTitleLabel;
    QLabel *errorStatusLabel;
    QTableWidget *errorTable;
    QPushButton *resetErrorsButton;
    QPushButton *errorRefButton;
    QPushButton *pushButton_3;
    QWidget *tab_2;
    QLineEdit *searchEdit;
    QTableWidget *tableWidget;
    QPushButton *copyButton;
    QPushButton *closeButton;

    void setupUi(QDialog *errorcodesdialog)
    {
        if (errorcodesdialog->objectName().isEmpty())
            errorcodesdialog->setObjectName("errorcodesdialog");
        errorcodesdialog->resize(400, 300);
        tabWidget = new QTabWidget(errorcodesdialog);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 100, 191, 171));
        tab = new QWidget();
        tab->setObjectName("tab");
        errorTitleLabel = new QLabel(tab);
        errorTitleLabel->setObjectName("errorTitleLabel");
        errorTitleLabel->setGeometry(QRect(10, 0, 49, 16));
        errorStatusLabel = new QLabel(tab);
        errorStatusLabel->setObjectName("errorStatusLabel");
        errorStatusLabel->setGeometry(QRect(70, 0, 49, 16));
        errorTable = new QTableWidget(tab);
        errorTable->setObjectName("errorTable");
        errorTable->setGeometry(QRect(10, 20, 71, 51));
        resetErrorsButton = new QPushButton(tab);
        resetErrorsButton->setObjectName("resetErrorsButton");
        resetErrorsButton->setGeometry(QRect(10, 100, 41, 24));
        errorRefButton = new QPushButton(tab);
        errorRefButton->setObjectName("errorRefButton");
        errorRefButton->setGeometry(QRect(60, 100, 41, 24));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(120, 100, 41, 24));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());
        searchEdit = new QLineEdit(errorcodesdialog);
        searchEdit->setObjectName("searchEdit");
        searchEdit->setGeometry(QRect(30, 30, 113, 22));
        tableWidget = new QTableWidget(errorcodesdialog);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(220, 50, 141, 111));
        copyButton = new QPushButton(errorcodesdialog);
        copyButton->setObjectName("copyButton");
        copyButton->setGeometry(QRect(250, 210, 75, 24));
        closeButton = new QPushButton(errorcodesdialog);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(310, 250, 75, 24));

        retranslateUi(errorcodesdialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(errorcodesdialog);
    } // setupUi

    void retranslateUi(QDialog *errorcodesdialog)
    {
        errorcodesdialog->setWindowTitle(QCoreApplication::translate("errorcodesdialog", "Dialog", nullptr));
        errorTitleLabel->setText(QCoreApplication::translate("errorcodesdialog", "TextLabel", nullptr));
        errorStatusLabel->setText(QCoreApplication::translate("errorcodesdialog", "TextLabel", nullptr));
        resetErrorsButton->setText(QCoreApplication::translate("errorcodesdialog", "PushButton", nullptr));
        errorRefButton->setText(QCoreApplication::translate("errorcodesdialog", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("errorcodesdialog", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("errorcodesdialog", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("errorcodesdialog", "Tab 2", nullptr));
        copyButton->setText(QCoreApplication::translate("errorcodesdialog", "\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        closeButton->setText(QCoreApplication::translate("errorcodesdialog", "\320\267\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class errorcodesdialog: public Ui_errorcodesdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORCODESDIALOG_H
