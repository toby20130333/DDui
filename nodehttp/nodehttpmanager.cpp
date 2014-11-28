#include "nodehttpmanager.h"

NodeHttpManager::NodeHttpManager(QObject *parent) :
    QObject(parent)
{
}

QObject* NodeHttpManager::CheckTaskApi(int cmd)
{
    if(!taskMap.isEmpty() || taskMap.contains(cmd))
    {
            QObject* obj = taskMap[cmd];
            return obj;
    }else{
            return NULL;
    }
}
void NodeHttpManager::addTask(int cmd, QStringList data)
{
    switch (cmd) {
    case 1000:
        if(!taskMap[cmd])
        {
            loginApi = new DDLoginApi();
            taskMap[cmd] = loginApi;
            connect(loginApi,SIGNAL(signalLoginApi(QStringList)),this,SLOT(slotLoginApi(QStringList)));
        }
        loginApi->initData(data);
        loginApi->nodeAction();
        break;
    case 1001:
    {
        if(!taskMap[cmd])
        {
            regApi = new DDRegisterApi();
            taskMap[cmd] = regApi;
            connect(regApi,SIGNAL(signalRegisterApi(QStringList)),this,SLOT(slotRegisterApi(QStringList)));
        }
        regApi->initData(data);
        regApi->nodeAction();
    }break;
    default:
        break;
    }
}

void NodeHttpManager::slotLoginApi(const QStringList &lst)
{
    emit sendMsgToUI(1000,lst);
}

void NodeHttpManager::slotRegisterApi(const QStringList &lst)
{
    emit sendMsgToUI(1001,lst);
}
