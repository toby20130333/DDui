#include "datainterface.h"
#include <QFileDialog>

DataInterface::DataInterface(QObject *parent) :
    QObject(parent),isConnected(false)
{
    creatConnection();
}

void DataInterface::slotRequestData(int cmd, QStringList parameterList)
{
   DDui::instance()->requestData(cmd,parameterList);
}

void DataInterface::slotResponseNotifyUI(bool error, int cmd, QStringList processResult)
{ 
    DDui::instance()->responseNotifyUI(error,cmd,processResult);
}

//=======================creat connection in first request(connection depdent instance)==========================
void DataInterface::creatConnection()
{
      connect(DDui::instance(),SIGNAL(signalNotifyUI(bool,int,QStringList)),this,SIGNAL(signalNotifyUI(bool,int,QStringList)));
      connect(DDui::instance(),SIGNAL(signalResponseDataReady(bool,int,QStringList)),this,SIGNAL(signalResponseDataReady(bool,int,QStringList)));
}

//改变鼠标的样式
void DataInterface::slotChangeCursor(int flag)
{
    switch(flag){
    case 0:
    {
        DDui::instance()->setCursor(QCursor(Qt::ArrowCursor));}
        break;
    case 1:
    {
        DDui::instance()->setCursor(QCursor(Qt::PointingHandCursor));}
        break;
    case 2:
    {
        DDui::instance()->setCursor(QCursor(Qt::SplitHCursor));}
        break;
    default:
        break;
    }
}









