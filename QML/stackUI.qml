import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Window 2.0

import DDInterface 1.0

ApplicationWindow {
    id:ddMainUI
    property alias mainID: ddMainUI
    width: 480
    height: 720
    visible: true
    flags: Qt.FramelessWindowHint
    Rectangle {
        color: "#009A61"
        anchors.fill: parent
    }
    toolBar: Rectangle {
        id:topBar
        width: parent.width
        height: 60
        color:"#00AA61"
        Button {
            id: backButton
            width: opacity ? 70 : 0
            anchors.left: parent.left
            anchors.leftMargin: 10
            opacity: stackView.depth > 1 ? 1 : 0
            anchors.verticalCenter: parent.verticalCenter
            antialiasing: true
            height: 40
            Behavior on opacity { NumberAnimation{} }
            style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: 136
                        implicitHeight: 36
                        border.width: control.activeFocus ? 2 : 1
                        border.color: "#351F47"
                        radius: 4
                        gradient: Gradient {
                            GradientStop { position: 0 ; color: control.pressed ? "#351F47" : "#3E2754" }
                            GradientStop { position: 1 ; color: control.pressed ? "#3E2754" : "#351F47" }
                        }
                    }
            }
            Text {
                anchors.verticalCenter: parent.verticalCenter
                text: "返回"
                font.pixelSize: 20
                color: "#ffffff"
                anchors.horizontalCenter: parent.horizontalCenter
            }
            MouseArea {
                id: backmouse
                anchors.fill: parent
                anchors.margins: -10
                onClicked: stackView.pop()
            }
        }
        Text {
            Behavior on x { NumberAnimation{ easing.type: Easing.OutCubic} }
            x: backButton.x +( (backButton.width >0)?40:100)+backButton.width;
            anchors.verticalCenter: parent.verticalCenter
            color: "#2f2253"
            text: qsTr("多多指教-专注Qt、QML")
            font.pixelSize: 28
            font.italic: false
            style: Text.Sunken
            font.family: "Times New Roman"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
        }
    }

    ListModel {
        id: pageModel
        ListElement {
            title: "用户注册"
            page: "RegisterUI.qml"
        }
        ListElement {
            title: "登陆"
            page: "LoginUI.qml"
        }
        ListElement {
            title: "聊天功能"
            page: "Chat.qml"
        }
        ListElement {
            title: "列表模式"
            page: "tableViewDemo.qml"
        }
        ListElement {
            title: "动态进度条"
            page: "main.qml"
        }
        ListElement {
            title: "圆形处理"
            page: "Gradientqml.qml"
        }
        ListElement {
            title: "矩形处理"
            page: "CanvaRectang.qml"
        }
    }
    StackView {
        id: stackView
        anchors.fill:parent
        delegate: StackViewDelegate {
            function transitionFinished(properties)
            {
                properties.exitItem.opacity = 1
            }
             pushTransition: StackViewTransition {
                PropertyAnimation {
                    target: enterItem
                    property: "width"
                    from: 0
                    to: stackView.width
                    duration: 200
                }
                PropertyAnimation {
                    target: exitItem
                    property: "opacity"
                    from:1
                    to: 0
                    duration: 100
                }
            }
        }
        initialItem: Item {
            width: parent.width
            height: parent.height
            ListView {
                model: pageModel
                anchors.fill: parent                
                delegate: AndroidDelegate {
                    text: title
                    onClicked: stackView.push(Qt.resolvedUrl(page))
                }
            }
        }        
        onCurrentItemChanged: {
            //console.log("ffffffffffffffffff"+stackView.currentItem)
            //currentItem.signalRegister.connect(ddMainUI.changePage);

            //currentItem.signalLogin.connect(ddMainUI.changePage);
            //console.log("ffffffffffdddddddddddddddfffffffff"+stackView.get(1,true));
            //find(function(item, index) { return item.isTheOne })
        }
    }
    Component.onCompleted: {
        stackView.push(Qt.resolvedUrl(pageModel.get(0).page));
        //stackView.currentItem.signalLogin.connect(ddMainUI.changePage);
    }
    DataInterface{
        id:dataInterface
    }
    Connections{
        target: dataInterface
        onSignalNotifyUI:
        {

        }
        onSignalResponseDataReady:{

        }
    }

    function changePage(id,qml)
    {
        console.log("ffffffffffffffffffffchangePagefffffffffffffffffffff "+id)
        if(id ==="register")
        {
            stackView.push(Qt.resolvedUrl(pageModel.get(0).page))
        }else if(id === "login")
        {
            stackView.push(Qt.resolvedUrl(pageModel.get(1).page))
        }
    }
    QtObject {
           id: globalObj
           property string name
           property int size
           property variant attributes
           signal signalConnectInterqml(string signalCmd,variant signalValue);
           function emitSignal(signalName,signalcmd,signalValue)
           {
               console.log("==========>hello in main.qml emit signal=======>signalName: " + signalName + "signalCmd :" + signalcmd);
//               switch(signalName){
//               case "register":changePage(signalName,"qml");break;
//               }
               changePage(signalName,"")
           }
       }
}
