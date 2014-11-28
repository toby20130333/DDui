#ifndef DDREGISTERAPI_H
#define DDREGISTERAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QVariant>

class DDRegisterApi : public QObject
{
    Q_OBJECT
public:
    explicit DDRegisterApi(QObject *parent = 0);
    ~DDRegisterApi();

    void initData(const QStringList& lst);

    bool nodeAction();
    QNetworkAccessManager *manager;
private:
    QStringList lstData;
signals:
    void signalRegisterApi(const QStringList& data);
public slots:
    void replyFinished(QNetworkReply*);
};

#endif // DDREGISTERAPI_H
