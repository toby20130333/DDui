#include "ddui.h"
#include <QApplication>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "interface/datainterface.h"
#include "xml/xbeltree.h"
#include "xml/xmlparsewin.h"
#include "xml/xmlitemparse.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    XmlItemParse win;
//    win.parseXML();
//    DDui* w = DDui::instance();
//    w->show();
//    QQuickView *view = new QQuickView;
//    view->setFlags(Qt::FramelessWindowHint);
//    view->setSource(QUrl("qrc:/stackUI.qml"));
//    view->show();

    qmlRegisterType<DataInterface>("DDInterface",1,0,"DataInterface");
    QQmlApplicationEngine engine;
    engine.load(QUrl::fromLocalFile(("QML/stackUI.qml")));
    return a.exec();
}
