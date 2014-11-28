#include "ddui.h"


DDui* DDui::_instance = NULL;

DDui* DDui::instance(QWidget *parent){
    if(_instance==NULL){
        _instance = new DDui();
    }
    return _instance;
}
DDui::DDui(QWidget *parent) :
    QWidget(parent)
{
    this->resize(480,720);
    connect(&nodeManager,SIGNAL(sendMsgToUI(int,QStringList)),this,SLOT(slotReponseToUI(int,QStringList)));
}
DDui::~DDui()
{

}

void DDui::requestData(int cmd, QStringList processResult)
{
    qDebug()<<"DDui::requestData "<<cmd<<" "<<processResult;
    if(cmd == 1000)
    {
        nodeManager.addTask(cmd,processResult);
    }else if(cmd == 1001)
    {
         nodeManager.addTask(cmd,processResult);
    }
}

void DDui::responseNotifyUI(bool error, int cmd, QStringList processResult)
{
        emit signalResponseDataReady(error,cmd,processResult);
}

void DDui::setSystemTray()
{

}

void DDui::slotReponseToUI(int cmd, const QStringList &lst)
{
   responseNotifyUI(false,cmd,lst);
}

