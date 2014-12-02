#ifndef XMLPARSEWIN_H
#define XMLPARSEWIN_H

#include <QMainWindow>
#include <QXmlStreamReader>
#include <QGroupBox>
#include <QFormLayout>
#include <QMap>
#include <QLineEdit>
#include <QPointer>
#include <QDebug>
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <QResizeEvent>
class XMLParseWin : public QMainWindow
{
    Q_OBJECT
public:
    explicit XMLParseWin(QWidget *parent = 0);
    ~XMLParseWin();
private slots:
    void parseXML();

private:
    QPointer<QVBoxLayout> _layout;
    QTreeWidget* tree;
    void setupUI();

    QMap<QString, QString> parsePerson(QXmlStreamReader& xml);
    void addElementDataToMap(QXmlStreamReader& xml,
                             QMap<QString, QString>& map) const;

    void addPersonsToUI(QList< QMap<QString,QString> >& persons);
protected:
    void resizeEvent(QResizeEvent* e);
};

#endif // XMLPARSEWIN_H
