import QtQuick 2.0
import QtQuick.XmlListModel 2.0

Item{

    XmlListModel {
        id: xmlModel
        source: "qrc:/Province.xml"
        query: "/provinces/province"
        // query the book title
        XmlRole { name: "code"; query: "@code/string()" }
        XmlRole { name: "name"; query: "@name/string()" }
        Component.onCompleted: {
            console.log("fuck...........xmlModel..............................."+xmlModel.count)
                showModel(xmlModel);
        }
    }
    XmlListModel {
        id: model2
        source: "qrc:/Province.xml"
        // XmlRole queries will be made on <book> elements
        query: "/provinces/province/city"
        // query the book's type (the '@' indicates 'type' is an attribute, not an element)
        XmlRole { name: "code"; query: "@code/string()" }

        // query the wanted attribute as a boolean
        XmlRole { name: "name"; query: "@name/string()" }
        Component.onCompleted: {
            console.log("fuck...........model2..............................."+xmlModel.count)
                showModel(xmlModel);
        }
    }
    function showModel(modeltmp)
    {
       for(var i=0;i<modeltmp.count;i++)
       {
           console.log("showModel ["+i+"]: "+modeltmp.get(i).Name);
       }
    }
}
