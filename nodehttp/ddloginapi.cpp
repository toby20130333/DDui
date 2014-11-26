#include "ddloginapi.h"
#define NODE_HOST_URL "http://localhost:3000"

DDLoginApi::DDLoginApi(QObject *parent) :
    QObject(parent),manager(NULL)
{
}

DDLoginApi::~DDLoginApi()
{

}
void DDLoginApi::initData(const QStringList &lst)
{
    lstData = lst;
}

bool DDLoginApi::nodeAction()
{
    if(manager == NULL){
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
    }
    //http://localhost:8888/select?aa=001&bb=002
    //http://localhost:3000/login?username=www&passwd=123
    QString hostUrl(NODE_HOST_URL);
    QString url("/fuck?");
    QString json ="";
    json.append("username=");
    if(lstData.isEmpty() && lstData.count()<2)
    {
        return false;
    }
    json.append(lstData.at(0));
    json.append("&password=");
    json.append(lstData.at(1));

    qDebug()<<" url "<<url<<" urlHost "<<hostUrl <<" json "<<json;
    //use post
    QNetworkRequest request;
    QString postUrl("");
    postUrl.append(hostUrl);
    postUrl.append(url);
    request.setUrl(QUrl(postUrl));
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    manager->post(request,json.toUtf8().data());
    qDebug()<<" Post Url "<<postUrl<<" post body "<<json;
}

void DDLoginApi::replyFinished(QNetworkReply *reply)
{
  //qDebug()<<"DDLoginApi::replyFinished "<<reply->readAll();
  emit signalLoginApi(QStringList()<< reply->readAll().data());
}
