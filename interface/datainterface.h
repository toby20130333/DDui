#ifndef DATAINTERFACE_H
#define DATAINTERFACE_H
/**********************************************************
qml 和 数据层通行接口类,在qml实例此接口和数据层通信
*********************************************************/
#include <QObject>
#include <QClipboard>
#include <QFileDialog>
#include "../ddui.h"

class DataInterface : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString strError READ getError WRITE setError)
public:
    explicit DataInterface(QObject *parent = 0);
    QString getError(){ return strError;}
    void setError(const QString& error){strError = error;}
signals:
    //notify qml the data has responsed
    void signalResponseDataReady(bool error,int cmd,QStringList finalData);
    //notify qml  to updata ui⋯⋯
    void signalNotifyUI(bool error,int cmd,QStringList notifyData);

public slots:
    //process the qml Request
    void slotRequestData(int cmd,QStringList parameterList);
    //process the qml Response
    void slotResponseNotifyUI(bool error,int cmd,QStringList processResult);

    void creatConnection();
    void slotChangeCursor(int flag);
private:
    QString strError;
    bool    isConnected;
};

#endif // DATAINTERFACE_H
