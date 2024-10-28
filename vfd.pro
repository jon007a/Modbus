QT += core gui widgets
QT += serialport
QT += quick qml quickcontrols2
QT += serialbus
QT += quick quickwidgets
QT += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connectionsettings.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    statistic.cpp \


HEADERS += \
    connectionsettings.h \
    mainwindow.h \
    qcustomplot.h \
    statistic.h \


FORMS += \
    connectionsettings.ui \
    mainwindow.ui \
    statistic.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Dial.qml \
    main.qml

RESOURCES += \
    dialcontrol.qrc
