#include "DDRegisterApi.h"
#define NODE_HOST_URL "http://localhost:3000"

DDRegisterApi::DDRegisterApi(QObject *parent) :
    QObject(parent),manager(NULL)
{
}

DDRegisterApi::~DDRegisterApi()
{

}
void DDRegisterApi::initData(const QStringList &lst)
{
    lstData = lst;
}

bool DDRegisterApi::nodeAction()
{
    if(manager == NULL){
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
    }
    //http://localhost:8888/select?aa=001&bb=002
    //http://localhost:3000/login?username=www&passwd=123
    QString hostUrl(NODE_HOST_URL);
    QString url("/register?");
    QString json ="";
    json.append("username=");
    if(lstData.isEmpty() && lstData.count()<7)
    {
        return false;
    }
    json.append(lstData.at(0));
    json.append("&password=");
    json.append(lstData.at(1));
    json.append("&nickname=");
    json.append(lstData.at(2));
    json.append("&email=");
    json.append(lstData.at(3));
    json.append("&sex=");
    json.append(lstData.at(4));
    json.append("&profession=");
    json.append(lstData.at(5));
    json.append("&location=");
    json.append(lstData.at(6));

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

void DDRegisterApi::replyFinished(QNetworkReply *reply)
{
  //qDebug()<<"DDRegisterApi::replyFinished "<<reply->readAll();
  emit signalRegisterApi(QStringList()<< reply->readAll().data());
}
