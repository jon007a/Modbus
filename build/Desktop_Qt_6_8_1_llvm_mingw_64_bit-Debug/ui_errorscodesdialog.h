/********************************************************************************
** Form generated from reading UI file 'errorscodesdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORSCODESDIALOG_H
#define UI_ERRORSCODESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_errorscodesdialog
{
public:

    void setupUi(QDialog *errorscodesdialog)
    {
        if (errorscodesdialog->objectName().isEmpty())
            errorscodesdialog->setObjectName("errorscodesdialog");
        errorscodesdialog->resize(400, 300);

        retranslateUi(errorscodesdialog);

        QMetaObject::connectSlotsByName(errorscodesdialog);
    } // setupUi

    void retranslateUi(QDialog *errorscodesdialog)
    {
        errorscodesdialog->setWindowTitle(QCoreApplication::translate("errorscodesdialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class errorscodesdialog: public Ui_errorscodesdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORSCODESDIALOG_H
