#ifndef XMLITEMPARSE_H
#define XMLITEMPARSE_H

#include <QObject>
#include <QXmlStreamReader>
#include <QGroupBox>
#include <QFormLayout>
#include <QMap>
#include <QLineEdit>
#include <QPointer>
#include <QDebug>
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <QFile>
#include <QMessageBox>

class XmlItemParse : public QObject
{
    Q_OBJECT
public:
    explicit XmlItemParse(QObject *parent = 0);
    ~XmlItemParse();
public slots:
    QString parseXML();

private:
    QPointer<QVBoxLayout> _layout;
    QTreeWidget* tree;
    void setupUI();

    QMap<QString, QString> parsePerson(QXmlStreamReader& xml);
    void addElementDataToMap(QXmlStreamReader& xml,
                             QMap<QString, QString>& map) const;
public slots:
    QString addPersonsToUI(QList< QMap<QString,QString> >& persons);
};

#endif // XMLITEMPARSE_H
