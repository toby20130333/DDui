#ifndef NODEHTTPMANAGER_H
#define NODEHTTPMANAGER_H

#include <QObject>
#include <QMap>
#include "ddloginapi.h"
#include "ddregisterapi.h"
#include "ddcityinsertapi.h"

class NodeHttpManager : public QObject
{
    Q_OBJECT
public:
    explicit NodeHttpManager(QObject *parent = 0);

    QObject* CheckTaskApi(int cmd);

    void addTask(int cmd,QStringList data);

    QMap<int,QObject*> taskMap;


    DDLoginApi* loginApi;
    DDRegisterApi* regApi;
    DDCityInsertApi* cityApi;

signals:
   void sendMsgToUI(int cmd,const QStringList& lst);
public slots:
    void slotLoginApi(const QStringList& lst);
    void slotRegisterApi(const QStringList& lst);
    void slotCityAddApi(const QStringList& lst);
};

#endif // NODEHTTPMANAGER_H
