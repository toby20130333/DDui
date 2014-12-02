import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

import DDInterface 1.0
import "./"
Rectangle {
//    width: Screen.desktopAvailableWidth
//    height: Screen.desktopAvailableHeight
//    property alias aliasID: parent
    id:loginUi
    width: 480
    height: 660
    color: "#00ffffff"
    radius: 10
    signal signalRegister(string id);

//    BorderImage {
//        id: borderImage1
//        x: 0
//        y: 0
//        width: loginUi.width
//        height: loginUi.height
//        source: "file:///D:/Users/Administrator/WebstormProjects/QtClub/nodeclub/public/images/duo-logo.png"
        Text {
            id: text7
            x: 37
            y: 57
            width: 411
            height: 74
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
//    }
    Rectangle {
        id: rectangle1
        x: 132
        y: 238
        width: 270
        height: 49
        color: "#ffffff"
        radius: 5
        border.color: "#433e4c"
    }

    Rectangle {
        id: rectangle2
        x: 132
        y: 314
        width: 270
        height: 51
        color: "#ffffff"
        radius: 5
        border.color: "#433e4c"
    }
    TextField {
        id: textInput1
        x: 134
        y: 240
        width: 266
        height: 45
//        color: "#433e4c"
//        text: qsTr("tb1210582@126.com")
        clip: true
        placeholderText: "字母,下划线"
        selectByMouse : true
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 20
    }

    TextField {
        id: textInput2
        x: 134
        y: 316
        width: 266
        height: 47
//        color: "#433e4c"
//        text: qsTr("123456tb")
        placeholderText: "6-12位数"
        clip: true
        echoMode: TextInput.Password
//        selectionColor: "#185690"
        horizontalAlignment: Text.AlignLeft
        font.pixelSize: 20
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: text1
        x: 74
        y: 246
        width: 24
        height: 25
        text: qsTr("用户名:")
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 16
        font.bold: true
        color: "#351F47"
    }

    Text {
        id: text2
        x: 85
        y: 328
        width: 30
        height: 24
        text: qsTr("密码:")
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 16
        font.bold: true
        color: "#351F47"
    }

    Button {
        id: rectangle3
        x: 132
        y: 391
        width: 270
        height: 51
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
            id: text3
            x: 34
            y: 7
            width: 169
            height: 38
            text: qsTr("登     陆")
            font.bold: true
            color: "#ffffff"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 20
        }
        MouseArea{
            id:ma
            anchors.bottomMargin: 0
            anchors.topMargin: 0
            anchors.rightMargin: -14
            anchors.leftMargin: -14
            anchors.fill: parent
            onClicked: {
                var lst=[textInput1.text,textInput2.text];
                dataInterface.slotRequestData(1000,lst);
            }
        }
    }

    Text {
        id: text4
        x: 141
        y: 506
        text: qsTr("忘记密码")
        font.underline: true
        font.pixelSize: 18
    }

    Text {
        id: text5
        x: 296
        y: 506
        text: qsTr("注册用户")
        font.underline: true
        font.pixelSize: 17
        MouseArea{
            id:mareg
            anchors.fill: parent
            onClicked: {
//                var lst=[0];
//                dataInterface.slotRequestData(1001,lst);
                globalObj.emitSignal("register","","");
                signalRegister("register");
            }
        }
    }

    Text {
        id: text6
        x: 125
        y: 631
        text: qsTr(" Certificate Copyright ©2014 多多指教 版权所有")
        font.pixelSize: 15
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
                console.log("finalData "+finalData)
        }
    }
}
