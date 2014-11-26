import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1

Rectangle {
    id: rectangle1
    width: 480
    height: 660
    signal signalLogin(string id);
    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#ffffff"
        }

        GradientStop {
            position: 1
            color: "#000000"
        }
    }
    border.color: "#2c3a36"

    Text {
        id: text1
        x: 65
        y: 121
        width: 56
        height: 21
        text: qsTr("用户名:")
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 12
    }

    Rectangle {
        id: rectangle2
        x: 134
        y: 108
        width: 238
        height: 47
        color: "#ffffff"
        border.color: "#2c3a36"

        TextInput {
            id: textInput1
            y: 14
            height: 20
            text: qsTr("tb1210582007")
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.rightMargin: 4
            anchors.leftMargin: 4
            font.pixelSize: 24
        }
    }

    Text {
        id: text2
        x: 60
        y: 186
        width: 61
        height: 21
        text: qsTr("昵称:")
        font.pixelSize: 12
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Rectangle {
        id: rectangle3
        x: 134
        y: 173
        width: 238
        height: 47
        color: "#ffffff"
        TextInput {
            id: textInput2
            text: qsTr("")
            anchors.fill: parent
            anchors.leftMargin: 4
            font.pixelSize: 24
            anchors.bottomMargin: 4
            anchors.topMargin: 4
            anchors.rightMargin: 4
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }
        border.color: "#2c3a36"
    }

    Text {
        id: text3
        x: 65
        y: 252
        width: 56
        height: 21
        text: qsTr("密码:")
        font.pixelSize: 12
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Rectangle {
        id: rectangle4
        x: 134
        y: 238
        width: 238
        height: 47
        color: "#ffffff"
        TextInput {
            id: textInput3
            text: qsTr("")
            echoMode: TextInput.Password
            anchors.fill: parent
            anchors.leftMargin: 4
            font.pixelSize: 24
            anchors.bottomMargin: 4
            anchors.topMargin: 4
            anchors.rightMargin: 4
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }
        border.color: "#2c3a36"
    }

    Text {
        id: text4
        x: 65
        y: 317
        width: 56
        height: 21
        text: qsTr("确认密码:")
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 12
        horizontalAlignment: Text.AlignHCenter
    }

    Rectangle {
        id: rectangle5
        x: 134
        y: 304
        width: 238
        height: 47
        color: "#ffffff"
        TextInput {
            id: textInput4
            text: qsTr("")
            echoMode: TextInput.Password
            anchors.fill: parent
            anchors.leftMargin: 4
            font.pixelSize: 24
            anchors.bottomMargin: 4
            anchors.topMargin: 4
            anchors.rightMargin: 4
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }
        border.color: "#2c3a36"
    }
    Text {
        id: text6
        x: 65
        y: 445
        width: 56
        height: 21
        text: qsTr("性别:")
        font.pixelSize: 12
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
    ExclusiveGroup { id: group }
    RadioButton {
        id:sexRadio
        x: 134
        y: 450
        text: "男"
        checked: true
        exclusiveGroup: group
        style: RadioButtonStyle {
            indicator: Rectangle {
                    implicitWidth: 16
                    implicitHeight: 16
                    radius: 9
                    border.color: control.activeFocus ? "darkblue" : "gray"
                    border.width: 1
                    Rectangle {
                        anchors.fill: parent
                        visible: control.checked
                        color: "#555"
                        radius: 9
                        anchors.margins: 4
                    }
            }
        }
     }
    RadioButton {
        id: sexRadio1
        x: 203
        y: 450
        exclusiveGroup: group
        text: qsTr("女")
        style: RadioButtonStyle {
            indicator: Rectangle {
                radius: 9
                implicitHeight: 16
                Rectangle {
                    color: "#555555"
                    radius: 9
                    anchors.fill: parent
                    visible: control.checked
                    anchors.margins: 4
                }
                border.width: 1
                implicitWidth: 16
                border.color: control.activeFocus ? "darkblue" : "gray"
            }
        }
    }

    Text {
        id: text5
        x: 65
        y: 386
        width: 56
        height: 21
        text: qsTr("邮箱:")
        font.pixelSize: 12
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Rectangle {
        id: rectangle6
        x: 134
        y: 370
        width: 238
        height: 47
        color: "#ffffff"
        TextInput {
            id: textInput5
            text: qsTr("")
            anchors.fill: parent
            anchors.leftMargin: 4
            font.pixelSize: 24
            anchors.bottomMargin: 4
            anchors.topMargin: 4
            anchors.rightMargin: 4
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }
        border.color: "#2c3a36"
    }

    Text {
        id: text7
        x: 65
        y: 487
        width: 56
        height: 21
        text: qsTr("职业:")
        font.pixelSize: 12
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
    ComboBox {
        x: 134
        y: 487
        currentIndex: 2
        model: ListModel {
            id: cbItems
            ListElement { text: "UI设计师"; color: "Yellow" }
            ListElement { text: "交互设计师"; color: "Green" }
            ListElement { text: "前端设计师"; color: "Brown" }
            ListElement { text: "软件开发师"; color: "Green" }
            ListElement { text: "数据挖掘师"; color: "Red" }
        }
        width: 100
        onCurrentIndexChanged: console.debug(cbItems.get(currentIndex).text + ", " + cbItems.get(currentIndex).color)

        style: ComboBoxStyle {
            background: Rectangle {
              implicitWidth: 100
              implicitHeight: 25
              color: "#FFFFFF"
              border.width: 1
              border.color: !control.enabled ? "#DADAD9" : control.activeFocus ? "#3C3C3B" : "#9D9C9C"
              antialiasing: true
              Rectangle {
                id: glyph
                width: 10
                height: 10
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
                color: !control.enabled ? "#DADAD9" : control.hovered ? "#1D5086" : "#5791CD"
                states: State {
                  name: "inverted"
                  when: __popup.__popupVisible
                  PropertyChanges { target: glyph; rotation: 180 }
                }

                transitions: Transition {
                  RotationAnimation { duration: 50; direction: RotationAnimation.Clockwise }
                }
              }
            }
            label: Label {
              verticalAlignment: Qt.AlignVCenter
              anchors.left: parent.left
              anchors.leftMargin: 5
              text: control.currentText
              color: !control.enabled ? "#DADAD9" : "#6F6E6E"
              anchors.fill: parent
              font.pixelSize: 12
            }
          }
    }

    Text {
        id: text8
        x: 65
        y: 529
        width: 56
        height: 21
        text: qsTr("现居:")
        font.pixelSize: 12
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
    ComboBox {
        x: 134
        y: 529
        currentIndex: 2
        model: ListModel {
            id: cbItems2
            ListElement { text: "上海"; color: "Yellow" }
            ListElement { text: "北京"; color: "Green" }
            ListElement { text: "湖南"; color: "Brown" }
            ListElement { text: "深圳"; color: "Green" }
            ListElement { text: "广东"; color: "Red" }
        }
        width: 100
        onCurrentIndexChanged: console.debug(cbItems2.get(currentIndex).text + ", " + cbItems2.get(currentIndex).color)

        style: ComboBoxStyle {
            background: Rectangle {
              implicitWidth: 100
              implicitHeight: 25
              color: "#FFFFFF"
              border.width: 1
              border.color: !control.enabled ? "#DADAD9" : control.activeFocus ? "#3C3C3B" : "#9D9C9C"
              antialiasing: true
              Rectangle {
                id: glyph2
                width: 10
                height: 10
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
                color: !control.enabled ? "#DADAD9" : control.hovered ? "#1D5086" : "#5791CD"
                states: State {
                  name: "inverted"
                  when: __popup.__popupVisible
                  PropertyChanges { target: glyph2; rotation: 180 }
                }

                transitions: Transition {
                  RotationAnimation { duration: 50; direction: RotationAnimation.Clockwise }
                }
              }
            }
            label: Label {
              verticalAlignment: Qt.AlignVCenter
              anchors.left: parent.left
              anchors.leftMargin: 5
              text: control.currentText
              color: !control.enabled ? "#DADAD9" : "#6F6E6E"
              anchors.fill: parent
              font.pixelSize: 12
            }
          }
    }

    CheckBox {
        x: 131
        y: 572
        text: "我已阅读并接受版权声明"
        style: CheckBoxStyle {
            indicator: Rectangle {
                    implicitWidth: 16
                    implicitHeight: 16
                    radius: 3
                    border.color: control.activeFocus ? "darkblue" : "gray"
                    border.width: 1
                    Rectangle {
                        visible: control.checked
                        color: "#555"
                        border.color: "#333"
                        radius: 1
                        anchors.margins: 4
                        anchors.fill: parent
                    }
            }
        }
    }
    Text {
        id: text10
        x: 288
        y: 611
        width: 99
        height: 24
        color: "#ffffff"
        text: qsTr("已经有账号? <a href='/' ><font color='white'>登录</font></a>")
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 12
        MouseArea{
            id:mareg
            anchors.fill: parent
            onClicked: {
                console.log("fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff")
                signalLogin("login");
            }
        }
    }
    Rectangle {
        id: rectangle7
        x: 131
        y: 605
        width: 136
        height: 36
        color: "#d75031"
        border.width: 0

        Text {
            id: text9
            x: 32
            y: 12
            width: 71
            height: 16
            text: qsTr("注   册")
            font.bold: false
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 20
        }
    }



}
