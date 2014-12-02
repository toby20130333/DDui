#include "xmlparsewin.h"
#include <QFile>
#include <QMessageBox>
#include <QHeaderView>
XMLParseWin::XMLParseWin(QWidget *parent) : QMainWindow(parent)
{
    this->resize(400,400);
    tree = new QTreeWidget(this);
    QStringList labels;
    labels << tr("位置") << tr("区域代码");
    tree->header()->setSectionResizeMode(QHeaderView::Stretch);
    tree->setHeaderLabels(labels);
    parseXML();
}

XMLParseWin::~XMLParseWin()
{

}

void XMLParseWin::parseXML() {
    /* We'll parse the example.xml */
    QFile* file = new QFile(":/Province.xml");
    /* If we can't open it, let's show an error message. */
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this,
                              "XMLParseWin::parseXML",
                              "Couldn't open Province.xml",
                              QMessageBox::Ok);
        return;
    }
    /* QXmlStreamReader takes any QIODevice. */
    QXmlStreamReader xml(file);
    QList< QMap<QString,QString> > persons;
    /* We'll parse the XML until we reach end of it.*/
    while(!xml.atEnd() &&
            !xml.hasError()) {
        /* Read next element.*/
        QXmlStreamReader::TokenType token = xml.readNext();
        /* If token is just StartDocument, we'll go to next.*/
        if(token == QXmlStreamReader::StartDocument) {
            continue;
        }
        /* If token is StartElement, we'll see if we can read it.*/
        if(token == QXmlStreamReader::StartElement) {
            /* If it's named persons, we'll go to the next.*/
            if(xml.name() == "provinces") {
                continue;
            }
            /* If it's named person, we'll dig the information from there.*/
            if(xml.name() == "province") {
                persons.append(this->parsePerson(xml));
            }
        }
    }
    /* Error handling. */
    if(xml.hasError()) {
        QMessageBox::critical(this,
                              "XMLParseWin::parseXML",
                              xml.errorString(),
                              QMessageBox::Ok);
    }
    /* Removes any device() or data from the reader
     * and resets its internal state to the initial state. */
    xml.clear();
    this->addPersonsToUI(persons);
}

QMap<QString, QString> XMLParseWin::parsePerson(QXmlStreamReader& xml) {
    QMap<QString, QString> person;
    /* Let's check that we're really getting a person. */
    if(xml.tokenType() != QXmlStreamReader::StartElement &&
            xml.name() == "province") {
        return person;
    }
    /* Let's get the attributes for person */
    QXmlStreamAttributes attributes = xml.attributes();
    /* Let's check that person has id attribute. */
    if(attributes.hasAttribute("id")) {
        /* We'll add it to the map. */
        person["id"] = attributes.value("id").toString();
    }
    if(attributes.hasAttribute("name")) {
        /* We'll add it to the map. */
        person["name"] = attributes.value("name").toString();
    }
    /* Next element... */
    xml.readNext();
    /*
     * We're going to loop over the things because the order might change.
     * We'll continue the loop until we hit an EndElement named person.
     */
    while(!(xml.tokenType() == QXmlStreamReader::EndElement &&
            xml.name() == "province")) {
        if(xml.tokenType() == QXmlStreamReader::StartElement) {
            /* We've found first name. */
            if(xml.name() == "city") {
                //qDebug()<<"name === city?  ";
                this->addElementDataToMap(xml, person);
            }
        }
        /* ...and next... */
        xml.readNext();
    }
    //qDebug()<<"person MAP  "<<person;
    return person;
}

void XMLParseWin::addElementDataToMap(QXmlStreamReader& xml,
                                      QMap<QString, QString>& map) const {
    /* We need a start element, like <foo> */
    if(xml.tokenType() != QXmlStreamReader::StartElement) {
        //qDebug()<<"tokenType????????  "<<map;
        return;
    }
    /* Let's read the name... */
    QString elementName,codeName;
    QXmlStreamAttributes attributes = xml.attributes();
    /* Let's check that person has id attribute. */
    if(attributes.hasAttribute("cityname")) {
        /* We'll add it to the map. */
        elementName = attributes.value("cityname").toString();
    }
    if(attributes.hasAttribute("code")) {
        /* We'll add it to the map. */
        codeName = attributes.value("code").toString();
    }
    /* ...go to the next. */
    xml.readNext();
    /*
     * This elements needs to contain Characters so we know it's
     * actually data, if it's not we'll leave.
     */
    /* Now we can add it to the map.*/
    qDebug()<<"elementName  "<<elementName<<" codeName "<<codeName;
    map.insert(elementName,"cityname");
    map.insert(codeName,"code");
}

void XMLParseWin::addPersonsToUI(QList< QMap<QString,QString> >& persons) {
//    qDebug()<<" addPersonsToUI ";
    tree->resize(this->size());
    for(int i=0;i<persons.count();i++)
    {
         //qDebug()<<"addPersonsToUI  "<<i<<persons.at(i).keys("code")
            //    <<" cityname "<<persons.at(i).keys("cityname");
        QTreeWidgetItem *cities = new QTreeWidgetItem(tree);
        cities->setText(0, persons.at(i).value("name"));
        cities->setText(1, persons.at(i).value("id"));
        for(int j=0;j<persons.at(i).keys("cityname").count();j++)
        {
             //qDebug()<<" current ........["<<j<<"]"<<persons.at(i).keys("cityname").at(j);
             QTreeWidgetItem* item = new QTreeWidgetItem(cities);
             item->setText(0,(persons.at(i).keys("cityname").at(j)));
             item->setText(1,(persons.at(i).keys("code").at(j)));
        }
    }
}

void XMLParseWin::resizeEvent(QResizeEvent *e)
{
  tree->resize(this->size());
}
