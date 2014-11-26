import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Window 2.0
import QtQuick.Controls.Styles 1.1
import QtGraphicalEffects 1.0

Item {
    width: 400
    height: 262
    visible: true
//    flags:Qt.FramelessWindowHint
    ListModel {
        id: libraryModel
        ListElement{ title: "\u4e0d\u80fd\u4e3a\u7a7a" ; author: "Gabriel";price:"1623$" }
        ListElement{ title: "QML解释语言QML解释语言QML解释语言QML解释语言QML解释语言"    ; author: "Jens" ;price:"123$"}
        ListElement{ title: "Qt框架"   ; author: "Frerik" ;price:"1253$"}
        ListElement{ title: "Js框架"   ; author: "Frik";price:"1243$" }
        ListElement{ title: "Nodejs框架"   ; author: "Ferik";price:"113$" }
        ListElement{ title: "Android框架"   ; author: "derik";price:"123$" }
        ListElement{ title: "iOs框架"   ; author: "ik" ;price:"13$"}
        ListElement{ title: "Php框架"   ; author: "derik";price:"1$" }
        ListElement{ title: "旗鱼系统"   ; author: "66k";price:"3$" }

    }
    Component {
        id: delegate1
        Item {
            clip: true
            Text {
                width: parent.width
                //                anchors.margins: 4
                //                anchors.left: parent.left
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                horizontalAlignment: Text.AlignHCenter
                elide: styleData.elideMode
                text: styleData.value !== undefined  ? styleData.value : ""
                color: styleData.selected ?"white":"#49A9E3"
                font.pixelSize: 14
                font.bold: true
            }
        }
    }
    TableView {
        id:table
        width: parent.width
        height: parent.height
        Component.onCompleted: {

        }
        style:  TableViewStyle{
            scrollBarBackground:
                Rectangle{
                height: 20
                gradient: Gradient {
                        GradientStop { position: 0.0; color: "lightsteelblue" }
                        GradientStop { position: 1.0; color: "blue" }
                    }
            }
            handle:
                Item{
                height: 20
            }
            decrementControl:
                Rectangle{
                height: 20
                width:20
                color: "red"
            }
            incrementControl:
                    Rectangle{
                    height: 20
                    width:20
                    color: "red"
            }
        }
        backgroundVisible: false
        TableViewColumn{
            id:parCol
            role: "title"  ;
            title: "语言" ;
            width: table.width/3
        }
        TableViewColumn{ role: "author" ; title: "作者" ; width: table.width/3 }
        TableViewColumn{role:"price";title:"价格";width:table.width/3}
        model: libraryModel
        headerDelegate: BorderImage{
            source: "qrc:/images/header.png"
            border{left:2;right:2;top:2;bottom:2}
            Text {
                text: styleData.value
                anchors.centerIn:parent
                color:"#333"
            }
        }
        itemDelegate:delegate1
        rowDelegate: Rectangle {
            height: (styleData.selected) ? 50 : 30
            Behavior on height{ NumberAnimation{} }

            color: styleData.selected ? "#8F314B" : (styleData.alternate? "#eee" : "#fff")
            LinearGradient {
                id:selected
                anchors.fill: parent
                start: Qt.point(0, 0)
                end: Qt.point(40, 40)
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "white" }
                    GradientStop { position: 0.5; color: "gray" }
                    GradientStop { position: 1.0; color: "black" }
                }
                visible: styleData.selected
                SequentialAnimation {
                    running: true; loops: Animation.Infinite
                    NumberAnimation { target:selected; property: "opacity"; to: 1.0; duration: 900}
                    NumberAnimation { target:selected; property: "opacity"; to: 0.5; duration: 900}
                }
            }
        }
        onClicked: {
            console.log(row);
        }
    }
}
