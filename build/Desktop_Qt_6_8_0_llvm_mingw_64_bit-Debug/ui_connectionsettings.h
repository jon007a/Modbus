/********************************************************************************
** Form generated from reading UI file 'connectionsettings.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONSETTINGS_H
#define UI_CONNECTIONSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ConnectionSettings
{
public:
    QComboBox *connectionTypeComboBox;
    QSpinBox *comPortSpinBox;
    QLineEdit *ipAddressLineEdit;
    QPushButton *applyButton;
    QComboBox *dataBitsComboBox;
    QComboBox *stopBitsComboBox;
    QComboBox *baudRateComboBox;
    QComboBox *parityComboBox;

    void setupUi(QDialog *ConnectionSettings)
    {
        if (ConnectionSettings->objectName().isEmpty())
            ConnectionSettings->setObjectName("ConnectionSettings");
        ConnectionSettings->resize(270, 438);
        connectionTypeComboBox = new QComboBox(ConnectionSettings);
        connectionTypeComboBox->setObjectName("connectionTypeComboBox");
        connectionTypeComboBox->setGeometry(QRect(30, 60, 72, 31));
        connectionTypeComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #757575; /* \320\236\321\201\320\275\320\276\320\262\320\275\320\276\320\271 \321\202\320\265\320\274\320\275\320\276-\321\201\320\265\321\200\321\213\320\271 \321\204\320\276\320\275 */\n"
"    color: white; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: 2px solid #616161; /* \320\221\320\276\320\273\320\265\320\265 \321\202\320\265\320\274\320\275\320\260\321\217 \321\201\320\265\321\200\320\260\321\217 \320\276\320\261\320\262\320\276\320\264\320\272\320\260 */\n"
"    border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"    padding: 5px; /* \320\222\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\270\320\271 \320\276\321\202\321\201\321\202\321\203\320\277 */\n"
"    font-size: 16px; /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"}\n"
""
                        "\n"
"QComboBox:hover {\n"
"    border: 2px solid #808080; /* \320\241\320\262\320\265\321\202\320\273\320\265\320\265 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QComboBox:editable {\n"
"    background-color: #757575; /* \320\242\320\265\320\274\320\275\320\276-\321\201\320\265\321\200\321\213\320\271 \321\204\320\276\320\275 \320\277\321\200\320\270 \321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    background-color: #757575; /* \320\244\320\276\320\275 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"    border: none; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \320\276\320\261\320\262\320\276\320\264\320\272\321\203 */\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/path/to/your/icon.png); /* \320\227\320\260"
                        "\320\274\320\265\320\275\320\270\321\202\320\265 \320\275\320\260 \320\277\321\203\321\202\321\214 \320\272 \320\262\320\260\321\210\320\265\320\271 \320\270\320\272\320\276\320\275\320\272\320\265 \321\201\321\202\321\200\320\265\320\273\320\272\320\270 */\n"
"    width: 10px; /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\270\320\272\320\276\320\275\320\272\320\270 */\n"
"    height: 10px; /* \320\222\321\213\321\201\320\276\321\202\320\260 \320\270\320\272\320\276\320\275\320\272\320\270 */\n"
"}\n"
"\n"
"QComboBox::indicator {\n"
"    width: 0; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \321\201\321\202\320\260\320\275\320\264\320\260\321\200\321\202\320\275\321\213\320\271 \320\270\320\275\320\264\320\270\320\272\320\260\321\202\320\276\321\200 */\n"
"    height: 0;\n"
"}\n"
""));
        comPortSpinBox = new QSpinBox(ConnectionSettings);
        comPortSpinBox->setObjectName("comPortSpinBox");
        comPortSpinBox->setGeometry(QRect(30, 104, 91, 31));
        comPortSpinBox->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"    background-color: #757575; /* \320\236\321\201\320\275\320\276\320\262\320\275\320\276\320\271 \321\201\320\262\320\265\321\202\320\273\320\276-\321\201\320\265\321\200\321\213\320\271 \321\204\320\276\320\275 */\n"
"    color: #212121; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: 2px solid #90A4AE; /* \320\221\320\276\320\273\320\265\320\265 \321\202\320\265\320\274\320\275\320\260\321\217 \321\201\320\265\321\200\320\260\321\217 \320\276\320\261\320\262\320\276\320\264\320\272\320\260 */\n"
"    border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 \320\264\320\273\321\217 \320\262\321\201\320\265\320\263\320\276 spin box */\n"
"    padding: 5px; /* \320\222\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\270\320\271 \320\276\321\202\321\201\321\202\321\203\320\277 */\n"
"    font-size: 16px; /* \320\240\320\260\320\267\320"
                        "\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"}\n"
"\n"
"QSpinBox::up-button, QSpinBox::down-button {\n"
"    background-color: #A9A9A9; /* \320\242\320\265\320\274\320\275\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 \320\264\320\273\321\217 \321\203\320\262\320\265\320\273\320\270\321\207\320\265\320\275\320\270\321\217/\321\203\320\274\320\265\320\275\321\214\321\210\320\265\320\275\320\270\321\217 */\n"
"    border: none; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \320\276\320\261\320\262\320\276\320\264\320\272\321\203 */\n"
"    width: 16px; /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\272\320\275\320\276\320\277\320\276\320\272 */\n"
"    height: 10px; /* \320\222\321\213\321\201\320\276\321\202\320\260 \320\272\320\275\320\276\320\277\320\276\320\272 \320\264\320\273\321\217 \320\261\320\276\320\273\320\265\320\265 \320\260\320\272\320\272\321\203\321\200\320\260\321\202\320\275\320\276\320\263\320\276 \320\262\320\270\320\264"
                        "\320\260 */\n"
"    border-radius: 5px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 \320\264\320\273\321\217 \320\272\320\275\320\276\320\277\320\276\320\272 */\n"
"    margin: 2px; /* \320\224\320\276\320\261\320\260\320\262\320\273\321\217\320\265\320\274 \320\275\320\265\320\261\320\276\320\273\321\214\321\210\320\276\320\271 \320\276\321\202\321\201\321\202\321\203\320\277 \320\274\320\265\320\266\320\264\321\203 \320\272\320\275\320\276\320\277\320\272\320\260\320\274\320\270 \320\270 spin box */\n"
"}\n"
"\n"
"QSpinBox::up-button:hover, QSpinBox::down-button:hover {\n"
"    background-color: #B0BEC5; /* \320\221\320\276\320\273\320\265\320\265 \321\201\320\262\320\265\321\202\320\273\321\213\320\271 \321\206\320\262\320\265\321\202 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QSpinBox::up-button:pressed, QSpinBox::down-button:pressed {\n"
"    bac"
                        "kground-color: #90A4AE; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"}\n"
"\n"
"QSpinBox::up-button:default {\n"
"    border: none; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \320\276\320\261\320\262\320\276\320\264\320\272\321\203 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216 */\n"
"}\n"
"\n"
"QSpinBox::down-button:default {\n"
"    border: none; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \320\276\320\261\320\262\320\276\320\264\320\272\321\203 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216 */\n"
"}\n"
""));
        ipAddressLineEdit = new QLineEdit(ConnectionSettings);
        ipAddressLineEdit->setObjectName("ipAddressLineEdit");
        ipAddressLineEdit->setGeometry(QRect(110, 60, 151, 31));
        ipAddressLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #757575; /* \320\236\321\201\320\275\320\276\320\262\320\275\320\276\320\271 \321\202\320\265\320\274\320\275\320\276-\321\201\320\265\321\200\321\213\320\271 \321\204\320\276\320\275 */\n"
"    color: white; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: 2px solid #616161; /* \320\221\320\276\320\273\320\265\320\265 \321\202\320\265\320\274\320\275\320\260\321\217 \321\201\320\265\321\200\320\260\321\217 \320\276\320\261\320\262\320\276\320\264\320\272\320\260 */\n"
"    border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"    padding: 5px; /* \320\222\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\270\320\271 \320\276\321\202\321\201\321\202\321\203\320\277 */\n"
"    font-size: 16px; /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"}\n"
""
                        "\n"
"QLineEdit:focus {\n"
"    border: 2px solid #4CAF50; /* \320\227\320\265\320\273\320\265\320\275\320\260\321\217 \320\276\320\261\320\262\320\276\320\264\320\272\320\260 \320\277\321\200\320\270 \321\204\320\276\320\272\321\203\321\201\320\265 */\n"
"    \n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #A9A9A9; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\264\320\273\321\217 \320\277\320\273\320\265\320\271\321\201\321\205\320\276\320\273\320\264\320\265\321\200\320\260 */\n"
"}\n"
""));
        applyButton = new QPushButton(ConnectionSettings);
        applyButton->setObjectName("applyButton");
        applyButton->setGeometry(QRect(100, 390, 161, 41));
        applyButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #757575; /* \320\236\321\201\320\275\320\276\320\262\320\275\320\276\320\271 \321\202\320\265\320\274\320\275\320\276-\321\201\320\265\321\200\321\213\320\271 \321\204\320\276\320\275 */\n"
"    color: white; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"    padding: 10px 20px; /* \320\222\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\270\320\271 \320\276\321\202\321\201\321\202\321\203\320\277 */\n"
"    font-size: 16px; /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"    border: 2px solid #616161; /* \320\221\320\276\320\273\320\265\320\265 \321\202\320\265\320\274\320\275\320\260\321\217 \321\201\320\265\321\200\320\260\321\217 \320\276\320\261\320\262\320\276\320\264\320\272\320\260 */\n"
""
                        "}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #808080; /* \320\241\320\262\320\265\321\202\320\273\320\265\320\265 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5a5a5a; /* \320\242\320\265\320\274\320\275\320\265\320\265 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"    padding-left: 12px; /* \320\241\320\264\320\262\320\270\320\263 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 \320\264\320\273\321\217 \321\215\321\204\321\204\320\265\320\272\321\202\320\260 \320\263\320\273\321\203\320\261\320\270\320\275\321\213 */\n"
"    padding-top: 12px;\n"
"}\n"
""));
        dataBitsComboBox = new QComboBox(ConnectionSettings);
        dataBitsComboBox->setObjectName("dataBitsComboBox");
        dataBitsComboBox->setGeometry(QRect(30, 190, 91, 31));
        dataBitsComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #757575; /* \320\236\321\201\320\275\320\276\320\262\320\275\320\276\320\271 \321\202\320\265\320\274\320\275\320\276-\321\201\320\265\321\200\321\213\320\271 \321\204\320\276\320\275 */\n"
"    color: white; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: 2px solid #616161; /* \320\221\320\276\320\273\320\265\320\265 \321\202\320\265\320\274\320\275\320\260\321\217 \321\201\320\265\321\200\320\260\321\217 \320\276\320\261\320\262\320\276\320\264\320\272\320\260 */\n"
"    border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"    padding: 5px; /* \320\222\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\270\320\271 \320\276\321\202\321\201\321\202\321\203\320\277 */\n"
"    font-size: 16px; /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"}\n"
""
                        "\n"
"QComboBox:hover {\n"
"    border: 2px solid #808080; /* \320\241\320\262\320\265\321\202\320\273\320\265\320\265 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QComboBox:editable {\n"
"    background-color: #757575; /* \320\242\320\265\320\274\320\275\320\276-\321\201\320\265\321\200\321\213\320\271 \321\204\320\276\320\275 \320\277\321\200\320\270 \321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    background-color: #757575; /* \320\244\320\276\320\275 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"    border: none; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \320\276\320\261\320\262\320\276\320\264\320\272\321\203 */\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/path/to/your/icon.png); /* \320\227\320\260"
                        "\320\274\320\265\320\275\320\270\321\202\320\265 \320\275\320\260 \320\277\321\203\321\202\321\214 \320\272 \320\262\320\260\321\210\320\265\320\271 \320\270\320\272\320\276\320\275\320\272\320\265 \321\201\321\202\321\200\320\265\320\273\320\272\320\270 */\n"
"    width: 10px; /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\270\320\272\320\276\320\275\320\272\320\270 */\n"
"    height: 10px; /* \320\222\321\213\321\201\320\276\321\202\320\260 \320\270\320\272\320\276\320\275\320\272\320\270 */\n"
"}\n"
"\n"
"QComboBox::indicator {\n"
"    width: 0; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \321\201\321\202\320\260\320\275\320\264\320\260\321\200\321\202\320\275\321\213\320\271 \320\270\320\275\320\264\320\270\320\272\320\260\321\202\320\276\321\200 */\n"
"    height: 0;\n"
"}\n"
""));
        stopBitsComboBox = new QComboBox(ConnectionSettings);
        stopBitsComboBox->setObjectName("stopBitsComboBox");
        stopBitsComboBox->setGeometry(QRect(30, 230, 91, 31));
        stopBitsComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #757575; /* \320\236\321\201\320\275\320\276\320\262\320\275\320\276\320\271 \321\202\320\265\320\274\320\275\320\276-\321\201\320\265\321\200\321\213\320\271 \321\204\320\276\320\275 */\n"
"    color: white; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: 2px solid #616161; /* \320\221\320\276\320\273\320\265\320\265 \321\202\320\265\320\274\320\275\320\260\321\217 \321\201\320\265\321\200\320\260\321\217 \320\276\320\261\320\262\320\276\320\264\320\272\320\260 */\n"
"    border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"    padding: 5px; /* \320\222\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\270\320\271 \320\276\321\202\321\201\321\202\321\203\320\277 */\n"
"    font-size: 16px; /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"}\n"
""
                        "\n"
"QComboBox:hover {\n"
"    border: 2px solid #808080; /* \320\241\320\262\320\265\321\202\320\273\320\265\320\265 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QComboBox:editable {\n"
"    background-color: #757575; /* \320\242\320\265\320\274\320\275\320\276-\321\201\320\265\321\200\321\213\320\271 \321\204\320\276\320\275 \320\277\321\200\320\270 \321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    background-color: #757575; /* \320\244\320\276\320\275 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"    border: none; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \320\276\320\261\320\262\320\276\320\264\320\272\321\203 */\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/path/to/your/icon.png); /* \320\227\320\260"
                        "\320\274\320\265\320\275\320\270\321\202\320\265 \320\275\320\260 \320\277\321\203\321\202\321\214 \320\272 \320\262\320\260\321\210\320\265\320\271 \320\270\320\272\320\276\320\275\320\272\320\265 \321\201\321\202\321\200\320\265\320\273\320\272\320\270 */\n"
"    width: 10px; /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\270\320\272\320\276\320\275\320\272\320\270 */\n"
"    height: 10px; /* \320\222\321\213\321\201\320\276\321\202\320\260 \320\270\320\272\320\276\320\275\320\272\320\270 */\n"
"}\n"
"\n"
"QComboBox::indicator {\n"
"    width: 0; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \321\201\321\202\320\260\320\275\320\264\320\260\321\200\321\202\320\275\321\213\320\271 \320\270\320\275\320\264\320\270\320\272\320\260\321\202\320\276\321\200 */\n"
"    height: 0;\n"
"}\n"
""));
        baudRateComboBox = new QComboBox(ConnectionSettings);
        baudRateComboBox->setObjectName("baudRateComboBox");
        baudRateComboBox->setGeometry(QRect(30, 150, 91, 31));
        baudRateComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #757575; /* \320\236\321\201\320\275\320\276\320\262\320\275\320\276\320\271 \321\202\320\265\320\274\320\275\320\276-\321\201\320\265\321\200\321\213\320\271 \321\204\320\276\320\275 */\n"
"    color: white; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: 2px solid #616161; /* \320\221\320\276\320\273\320\265\320\265 \321\202\320\265\320\274\320\275\320\260\321\217 \321\201\320\265\321\200\320\260\321\217 \320\276\320\261\320\262\320\276\320\264\320\272\320\260 */\n"
"    border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"    padding: 5px; /* \320\222\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\270\320\271 \320\276\321\202\321\201\321\202\321\203\320\277 */\n"
"    font-size: 16px; /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"}\n"
""
                        "\n"
"QComboBox:hover {\n"
"    border: 2px solid #808080; /* \320\241\320\262\320\265\321\202\320\273\320\265\320\265 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QComboBox:editable {\n"
"    background-color: #757575; /* \320\242\320\265\320\274\320\275\320\276-\321\201\320\265\321\200\321\213\320\271 \321\204\320\276\320\275 \320\277\321\200\320\270 \321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    background-color: #757575; /* \320\244\320\276\320\275 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"    border: none; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \320\276\320\261\320\262\320\276\320\264\320\272\321\203 */\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/path/to/your/icon.png); /* \320\227\320\260"
                        "\320\274\320\265\320\275\320\270\321\202\320\265 \320\275\320\260 \320\277\321\203\321\202\321\214 \320\272 \320\262\320\260\321\210\320\265\320\271 \320\270\320\272\320\276\320\275\320\272\320\265 \321\201\321\202\321\200\320\265\320\273\320\272\320\270 */\n"
"    width: 10px; /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\270\320\272\320\276\320\275\320\272\320\270 */\n"
"    height: 10px; /* \320\222\321\213\321\201\320\276\321\202\320\260 \320\270\320\272\320\276\320\275\320\272\320\270 */\n"
"}\n"
"\n"
"QComboBox::indicator {\n"
"    width: 0; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \321\201\321\202\320\260\320\275\320\264\320\260\321\200\321\202\320\275\321\213\320\271 \320\270\320\275\320\264\320\270\320\272\320\260\321\202\320\276\321\200 */\n"
"    height: 0;\n"
"}\n"
""));
        parityComboBox = new QComboBox(ConnectionSettings);
        parityComboBox->setObjectName("parityComboBox");
        parityComboBox->setGeometry(QRect(30, 270, 91, 31));
        parityComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #757575; /* \320\236\321\201\320\275\320\276\320\262\320\275\320\276\320\271 \321\202\320\265\320\274\320\275\320\276-\321\201\320\265\321\200\321\213\320\271 \321\204\320\276\320\275 */\n"
"    color: white; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: 2px solid #616161; /* \320\221\320\276\320\273\320\265\320\265 \321\202\320\265\320\274\320\275\320\260\321\217 \321\201\320\265\321\200\320\260\321\217 \320\276\320\261\320\262\320\276\320\264\320\272\320\260 */\n"
"    border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"    padding: 5px; /* \320\222\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\270\320\271 \320\276\321\202\321\201\321\202\321\203\320\277 */\n"
"    font-size: 16px; /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"}\n"
""
                        "\n"
"QComboBox:hover {\n"
"    border: 2px solid #808080; /* \320\241\320\262\320\265\321\202\320\273\320\265\320\265 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QComboBox:editable {\n"
"    background-color: #757575; /* \320\242\320\265\320\274\320\275\320\276-\321\201\320\265\321\200\321\213\320\271 \321\204\320\276\320\275 \320\277\321\200\320\270 \321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    background-color: #757575; /* \320\244\320\276\320\275 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"    border: none; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \320\276\320\261\320\262\320\276\320\264\320\272\321\203 */\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/path/to/your/icon.png); /* \320\227\320\260"
                        "\320\274\320\265\320\275\320\270\321\202\320\265 \320\275\320\260 \320\277\321\203\321\202\321\214 \320\272 \320\262\320\260\321\210\320\265\320\271 \320\270\320\272\320\276\320\275\320\272\320\265 \321\201\321\202\321\200\320\265\320\273\320\272\320\270 */\n"
"    width: 10px; /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\270\320\272\320\276\320\275\320\272\320\270 */\n"
"    height: 10px; /* \320\222\321\213\321\201\320\276\321\202\320\260 \320\270\320\272\320\276\320\275\320\272\320\270 */\n"
"}\n"
"\n"
"QComboBox::indicator {\n"
"    width: 0; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \321\201\321\202\320\260\320\275\320\264\320\260\321\200\321\202\320\275\321\213\320\271 \320\270\320\275\320\264\320\270\320\272\320\260\321\202\320\276\321\200 */\n"
"    height: 0;\n"
"}\n"
""));

        retranslateUi(ConnectionSettings);

        QMetaObject::connectSlotsByName(ConnectionSettings);
    } // setupUi

    void retranslateUi(QDialog *ConnectionSettings)
    {
        ConnectionSettings->setWindowTitle(QCoreApplication::translate("ConnectionSettings", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        connectionTypeComboBox->setPlaceholderText(QCoreApplication::translate("ConnectionSettings", "\321\202\320\270\320\277", nullptr));
        ipAddressLineEdit->setPlaceholderText(QCoreApplication::translate("ConnectionSettings", "\320\260\320\271\320\277\320\270 \320\270 \320\277\320\276\321\200\321\202", nullptr));
        applyButton->setText(QCoreApplication::translate("ConnectionSettings", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        dataBitsComboBox->setPlaceholderText(QCoreApplication::translate("ConnectionSettings", "datdbits", nullptr));
        stopBitsComboBox->setPlaceholderText(QCoreApplication::translate("ConnectionSettings", "stopBits", nullptr));
        baudRateComboBox->setCurrentText(QString());
        baudRateComboBox->setPlaceholderText(QCoreApplication::translate("ConnectionSettings", "baud", nullptr));
        parityComboBox->setPlaceholderText(QCoreApplication::translate("ConnectionSettings", "parity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectionSettings: public Ui_ConnectionSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONSETTINGS_H
