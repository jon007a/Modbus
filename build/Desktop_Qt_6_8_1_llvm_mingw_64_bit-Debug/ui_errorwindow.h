/********************************************************************************
** Form generated from reading UI file 'errorwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORWINDOW_H
#define UI_ERRORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ErrorWindow
{
public:
    QLabel *label;
    QComboBox *userComboBox;
    QDateEdit *startDateEdit;
    QDateEdit *endDateEdit;
    QPushButton *exportButton;
    QPushButton *refreshButton;
    QTableWidget *errorTable;

    void setupUi(QDialog *ErrorWindow)
    {
        if (ErrorWindow->objectName().isEmpty())
            ErrorWindow->setObjectName("ErrorWindow");
        ErrorWindow->resize(675, 414);
        label = new QLabel(ErrorWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 63, 20));
        userComboBox = new QComboBox(ErrorWindow);
        userComboBox->setObjectName("userComboBox");
        userComboBox->setGeometry(QRect(10, 40, 76, 26));
        startDateEdit = new QDateEdit(ErrorWindow);
        startDateEdit->setObjectName("startDateEdit");
        startDateEdit->setGeometry(QRect(10, 70, 110, 26));
        endDateEdit = new QDateEdit(ErrorWindow);
        endDateEdit->setObjectName("endDateEdit");
        endDateEdit->setGeometry(QRect(10, 100, 110, 26));
        exportButton = new QPushButton(ErrorWindow);
        exportButton->setObjectName("exportButton");
        exportButton->setGeometry(QRect(10, 170, 93, 29));
        refreshButton = new QPushButton(ErrorWindow);
        refreshButton->setObjectName("refreshButton");
        refreshButton->setGeometry(QRect(10, 130, 93, 29));
        errorTable = new QTableWidget(ErrorWindow);
        if (errorTable->columnCount() < 3)
            errorTable->setColumnCount(3);
        errorTable->setObjectName("errorTable");
        errorTable->setGeometry(QRect(130, 20, 531, 381));
        errorTable->setColumnCount(3);

        retranslateUi(ErrorWindow);

        QMetaObject::connectSlotsByName(ErrorWindow);
    } // setupUi

    void retranslateUi(QDialog *ErrorWindow)
    {
        ErrorWindow->setWindowTitle(QCoreApplication::translate("ErrorWindow", "\320\237\320\260\320\275\320\265\320\273\321\214 \320\276\321\210\320\270\320\261\320\276\320\272", nullptr));
        label->setText(QCoreApplication::translate("ErrorWindow", "TextLabel", nullptr));
        exportButton->setText(QCoreApplication::translate("ErrorWindow", "PushButton", nullptr));
        refreshButton->setText(QCoreApplication::translate("ErrorWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ErrorWindow: public Ui_ErrorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORWINDOW_H
