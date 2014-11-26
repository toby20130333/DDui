#ifndef DDUI_H
#define DDUI_H
#include <QWidget>
#include <QTabWidget>
#include <QHBoxLayout>
#include <QWebView>
#include <QStackedWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QLabel>
#include <QParallelAnimationGroup>
#include <QAbstractAnimation>
#include <QPropertyAnimation>
#include <QDesktopWidget>
#include <QApplication>
#include <QDir>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QFileDialog>

#include "nodehttp/nodehttpmanager.h"

class DDui : public QWidget
{
    Q_OBJECT
protected:
    static DDui *_instance;
    explicit DDui(QWidget *parent = 0);
public:
    static DDui* instance(QWidget *parent=0);
    ~DDui();

    void requestData(int cmd, QStringList processResult);
    void responseNotifyUI(bool error, int cmd, QStringList processResult);
    void setSystemTray();

//    YbHttpManager m_httpManager;

    NodeHttpManager nodeManager;
signals:
    void signalNotifyUI(bool,int,QStringList);
    void signalResponseDataReady(bool,int,QStringList);
    void signalDeleteDownload(QStringList,bool);
protected:
//    void mouseReleaseEvent(QMouseEvent *);
//    void enterEvent(QEvent *);
//    void leaveEvent(QEvent *);

//    void mousePressEvent(QMouseEvent *);
//    void mouseMoveEvent(QMouseEvent *);

//    void changeEvent(QEvent *);
public slots:
    void slotReponseToUI(int cmd,const QStringList& lst);
};
#endif // DDUI_H
