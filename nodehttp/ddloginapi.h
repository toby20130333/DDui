#ifndef DDLOGINAPI_H
#define DDLOGINAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QVariant>

class DDLoginApi : public QObject
{
    Q_OBJECT
public:
    explicit DDLoginApi(QObject *parent = 0);
    ~DDLoginApi();

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

#endif // DDLOGINAPI_H
