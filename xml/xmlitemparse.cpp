#include "xmlitemparse.h"

XmlItemParse::XmlItemParse(QObject *parent) : QObject(parent)
{

}

XmlItemParse::~XmlItemParse()
{

}
QString XmlItemParse::parseXML() {
    /* We'll parse the example.xml */
    QFile* file = new QFile(":/cities.xml");
    /* If we can't open it, let's show an error message. */
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        return "";
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
            if(xml.name() == "cities") {
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
    }
    /* Removes any device() or data from the reader
     * and resets its internal state to the initial state. */
    xml.clear();
    return this->addPersonsToUI(persons);
}

QMap<QString, QString> XmlItemParse::parsePerson(QXmlStreamReader& xml) {
    QMap<QString, QString> person;
    /* Let's check that we're really getting a person. */
    if(xml.tokenType() != QXmlStreamReader::StartElement &&
            xml.name() == "province") {
        return person;
    }
    /* Let's get the attributes for person */
    QXmlStreamAttributes attributes = xml.attributes();
    /* Let's check that person has id attribute. */
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
            if(xml.name() == "item") {
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

void XmlItemParse::addElementDataToMap(QXmlStreamReader& xml,
                                      QMap<QString, QString>& map) const {
    /* We need a start element, like <foo> */
    if(xml.tokenType() != QXmlStreamReader::StartElement) {
        //qDebug()<<"tokenType????????  "<<map;
        return;
    }
    /* Let's read the name... */
    QString elementName = xml.name().toString();

    /* ...go to the next. */
    xml.readNext();
    /*
     * This elements needs to contain Characters so we know it's
     * actually data, if it's not we'll leave.
     */
    /* Now we can add it to the map.*/
    //qDebug()<<"elementName  "<<elementName;
    map.insert(xml.text().toString(),"cityname");
}

QString XmlItemParse::addPersonsToUI(QList< QMap<QString,QString> >& persons) {

    QStringList lst;
    lst.clear();
    for(int i=0;i<persons.count();i++)
    {
        QString province = persons.at(i).value("name");//每个城市的省份
        QStringList cityList;
        cityList.clear();
        for(int j=0;j<persons.at(i).keys("cityname").count();j++)
        {
             QString cityJson;
             cityJson = "{\"city\":\"";
             cityJson.append(persons.at(i).keys("cityname").at(j));
             cityJson.append("\",\"code\":\"");
             cityJson.append("1000");
             cityJson.append("\",\"province\":\"");
             cityJson.append(province);
             cityJson.append("\",\"country\":\"");
             cityJson.append("china\"}");
             cityList.append(cityJson);
        }
        lst.append(cityList.join(","));
    }
    QString allCities = lst.join(",");
    allCities.prepend("[");
    allCities.append("]");
    return allCities;
}

