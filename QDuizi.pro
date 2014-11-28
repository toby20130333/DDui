#-------------------------------------------------
#
# Project created by QtCreator 2014-09-26T09:37:58
#
#-------------------------------------------------

QT       += core gui webkit quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webkitwidgets quickwidgets
TARGET = DDui
TEMPLATE = app
win32:{
RC_FILE += dd.rc
}
macx:{
ICON = images/logo/128_logo.icns
}

SOURCES += main.cpp \
    ddui.cpp \
    interface/datainterface.cpp \
    nodehttp/ddloginapi.cpp \
    nodehttp/nodehttpmanager.cpp \
    nodehttp/ddregisterapi.cpp

OTHER_FILES += \
    app.js \
    newduizi.js \
    qduizi.js \
    LoginUI.qml \
    DDMainUI.qml \
    QML/deployment.pri \
    QML/AndroidDelegate.qml \
    QML/CanvaRectang.qml \
    QML/CustomTab.qml \
    QML/DDMainUI.qml \
    QML/fuck.qml \
    QML/Gradientqml.qml \
    QML/LoginUI.qml \
    QML/main.qml \
    QML/mainTabView.qml \
    QML/stackUI.qml \
    QML/tableViewDemo.qml \
    QML/RegisterUI.qml

HEADERS += \
    ddui.h \
    interface/datainterface.h \
    nodehttp/ddloginapi.h \
    nodehttp/nodehttpmanager.h \
    nodehttp/ddregisterapi.h

SUBDIRS += \
    QML/RepeaterQml.pro

RESOURCES += \
    QML/qml.qrc
