#include "ddcityinsertapi.h"
#define NODE_HOST_URL "http://localhost:8080"

DDCityInsertApi::DDCityInsertApi(QObject *parent) : QObject(parent),manager(NULL)
{

}
DDCityInsertApi::~DDCityInsertApi()
{

}
void DDCityInsertApi::initData(const QStringList &lst)
{
    lstData = lst;
}

bool DDCityInsertApi::nodeAction()
{
    if(manager == NULL){
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
    }
    //http://localhost:8888/select?aa=001&bb=002
    //http://localhost:3000/login?username=www&passwd=123
    QString hostUrl(NODE_HOST_URL);
    QString url("/findcity?");

    //use post
    QString json ="";
    json.append("city=");
    if(lstData.isEmpty() && lstData.count()<2)
    {
        return false;
    }
    json.append(lstData.at(0));
    json.append("&code=");
    json.append(lstData.at(1));
//    XmlItemParse win;
//    QString json = win.parseXML();
//    json.prepend("data=");
    QNetworkRequest request;
    QString postUrl("");
    postUrl.append(hostUrl);
    postUrl.append(url);
    request.setUrl(QUrl(postUrl));
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    manager->post(request,json.toUtf8().data());
    qDebug()<<" Post Url "<<postUrl<<" post body "<<json;
}

void DDCityInsertApi::replyFinished(QNetworkReply *reply)
{
  //qDebug()<<"DDCityInsertApi::replyFinished "<<reply->readAll();
  emit signalLoginApi(QStringList()<< reply->readAll().data());
}

