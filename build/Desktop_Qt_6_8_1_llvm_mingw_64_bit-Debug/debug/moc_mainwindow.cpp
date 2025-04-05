/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10MainWindowE = QtMocHelpers::stringData(
    "MainWindow",
    "speedChanged",
    "",
    "speed",
    "motorSpeedUpdated",
    "motorSpeed",
    "progressbars",
    "progressValue",
    "progressbars2",
    "progressValue2",
    "progressbars4",
    "progressValue4",
    "slaveConnected",
    "slaveDisconnected",
    "on_actionrtu_triggered",
    "applySettings",
    "connectionType",
    "comPort",
    "baudRate",
    "dataBits",
    "stopBits",
    "parity",
    "ipAddress",
    "port",
    "onModbusReadReady",
    "onSliderValueChanged",
    "newValue",
    "sendSpeedChange",
    "requestDataFromModbus",
    "onSlaveConnected",
    "onSlaveDisconnected",
    "on_action_triggered",
    "on_action_2_triggered",
    "createUserTable",
    "username",
    "on_actionOpenManual_triggered",
    "on_startButton_clicked",
    "on_stopButton_clicked",
    "on_resetButton_clicked",
    "onModbusStateChanged",
    "QModbusDevice::State",
    "state",
    "on_disconnectButton_clicked",
    "on_actionRegister_triggered",
    "on_actionExportReport_triggered",
    "onManualSpeedEntered",
    "on_actionadminpanel_triggered",
    "on_actionWarnings_triggered",
    "saveErrorToDatabase",
    "errorCode",
    "readErrorStatus",
    "setCurrentUserr",
    "userId"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10MainWindowE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  206,    2, 0x06,    1 /* Public */,
       4,    1,  209,    2, 0x06,    3 /* Public */,
       6,    1,  212,    2, 0x06,    5 /* Public */,
       8,    1,  215,    2, 0x06,    7 /* Public */,
      10,    1,  218,    2, 0x06,    9 /* Public */,
      12,    0,  221,    2, 0x06,   11 /* Public */,
      13,    0,  222,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      14,    0,  223,    2, 0x08,   13 /* Private */,
      15,    8,  224,    2, 0x08,   14 /* Private */,
      24,    0,  241,    2, 0x08,   23 /* Private */,
      25,    1,  242,    2, 0x08,   24 /* Private */,
      27,    1,  245,    2, 0x08,   26 /* Private */,
      28,    0,  248,    2, 0x08,   28 /* Private */,
      29,    0,  249,    2, 0x08,   29 /* Private */,
      30,    0,  250,    2, 0x08,   30 /* Private */,
      31,    0,  251,    2, 0x08,   31 /* Private */,
      32,    0,  252,    2, 0x08,   32 /* Private */,
      33,    1,  253,    2, 0x08,   33 /* Private */,
      35,    0,  256,    2, 0x08,   35 /* Private */,
      36,    0,  257,    2, 0x08,   36 /* Private */,
      37,    0,  258,    2, 0x08,   37 /* Private */,
      38,    0,  259,    2, 0x08,   38 /* Private */,
      39,    1,  260,    2, 0x08,   39 /* Private */,
      42,    0,  263,    2, 0x08,   41 /* Private */,
      43,    0,  264,    2, 0x08,   42 /* Private */,
      44,    0,  265,    2, 0x08,   43 /* Private */,
      45,    0,  266,    2, 0x08,   44 /* Private */,
      46,    0,  267,    2, 0x08,   45 /* Private */,
      47,    0,  268,    2, 0x08,   46 /* Private */,
      48,    1,  269,    2, 0x08,   47 /* Private */,
      50,    0,  272,    2, 0x08,   49 /* Private */,
      51,    1,  273,    2, 0x08,   50 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QReal,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::Int,   16,   17,   18,   19,   20,   21,   22,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::QReal,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   52,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ZN10MainWindowE.offsetsAndSizes,
    qt_meta_data_ZN10MainWindowE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10MainWindowE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'speedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'motorSpeedUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'progressbars'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'progressbars2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'progressbars4'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slaveConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slaveDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionrtu_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'applySettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onModbusReadReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSliderValueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sendSpeedChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'requestDataFromModbus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSlaveConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSlaveDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_2_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createUserTable'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_actionOpenManual_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_startButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_stopButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_resetButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onModbusStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QModbusDevice::State, std::false_type>,
        // method 'on_disconnectButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionRegister_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionExportReport_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onManualSpeedEntered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionadminpanel_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionWarnings_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveErrorToDatabase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'readErrorStatus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setCurrentUserr'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->speedChanged((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 1: _t->motorSpeedUpdated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->progressbars((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->progressbars2((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->progressbars4((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->slaveConnected(); break;
        case 6: _t->slaveDisconnected(); break;
        case 7: _t->on_actionrtu_triggered(); break;
        case 8: _t->applySettings((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8]))); break;
        case 9: _t->onModbusReadReady(); break;
        case 10: _t->onSliderValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->sendSpeedChange((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 12: _t->requestDataFromModbus(); break;
        case 13: _t->onSlaveConnected(); break;
        case 14: _t->onSlaveDisconnected(); break;
        case 15: _t->on_action_triggered(); break;
        case 16: _t->on_action_2_triggered(); break;
        case 17: { bool _r = _t->createUserTable((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 18: _t->on_actionOpenManual_triggered(); break;
        case 19: _t->on_startButton_clicked(); break;
        case 20: _t->on_stopButton_clicked(); break;
        case 21: _t->on_resetButton_clicked(); break;
        case 22: _t->onModbusStateChanged((*reinterpret_cast< std::add_pointer_t<QModbusDevice::State>>(_a[1]))); break;
        case 23: _t->on_disconnectButton_clicked(); break;
        case 24: _t->on_actionRegister_triggered(); break;
        case 25: _t->on_actionExportReport_triggered(); break;
        case 26: _t->onManualSpeedEntered(); break;
        case 27: _t->on_actionadminpanel_triggered(); break;
        case 28: _t->on_actionWarnings_triggered(); break;
        case 29: _t->saveErrorToDatabase((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 30: _t->readErrorStatus(); break;
        case 31: _t->setCurrentUserr((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (MainWindow::*)(qreal );
            if (_q_method_type _q_method = &MainWindow::speedChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (MainWindow::*)(int );
            if (_q_method_type _q_method = &MainWindow::motorSpeedUpdated; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (MainWindow::*)(int );
            if (_q_method_type _q_method = &MainWindow::progressbars; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (MainWindow::*)(int );
            if (_q_method_type _q_method = &MainWindow::progressbars2; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (MainWindow::*)(int );
            if (_q_method_type _q_method = &MainWindow::progressbars4; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (MainWindow::*)();
            if (_q_method_type _q_method = &MainWindow::slaveConnected; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _q_method_type = void (MainWindow::*)();
            if (_q_method_type _q_method = &MainWindow::slaveDisconnected; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10MainWindowE.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::speedChanged(qreal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::motorSpeedUpdated(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::progressbars(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::progressbars2(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::progressbars4(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::slaveConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MainWindow::slaveDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
