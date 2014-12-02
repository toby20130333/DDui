#ifndef DDCITYINSERTAPI_H
#define DDCITYINSERTAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QVariant>
#include "xml/xmlitemparse.h"

class DDCityInsertApi : public QObject
{
    Q_OBJECT
public:
    explicit DDCityInsertApi(QObject *parent = 0);
    ~DDCityInsertApi();
    void initData(const QStringList& lst);

    bool nodeAction();
    QNetworkAccessManager *manager;
private:
    QStringList lstData;
signals:
    void signalLoginApi(const QStringList& data);
public slots:
    void replyFinished(QNetworkReply*);
};

#endif // DDCITYINSERTAPI_H
