import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1
import QtQuick.Window 2.0

Item {
//    title: qsTr("Hello World")
    width: 600
    height: 560
//    color: "#414141"
    visible:true
    Component{
        id:delegateItem
        Rectangle{
            width: parent.width
            height: 2
            radius: 2
            color: "red"
        }
    }
    ColumnLayout {
        anchors.fill: parent
        Rectangle {
            color: "#414141"
            Layout.fillWidth: true
            Layout.preferredHeight: 50
            Label {
                text: "顶部工具栏"
                anchors.centerIn: parent
                font.bold: true
            }
        }
        SplitView {
            Layout.fillHeight: true
            Layout.fillWidth: true
            orientation: Qt.Horizontal
//            handleDelegate: delegateItem
            SplitView {
                Layout.fillHeight: true
                Layout.fillWidth: true
                orientation: Qt.Vertical
//                handleDelegate: delegateItem
                Rectangle {
                    color: "#565656"
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.minimumWidth: 400
                    Layout.preferredHeight: 400
                    border.width: 2
                    border.color: "gray"
                    Label {
                        text: "聊天内容显示栏"
                        anchors.centerIn: parent
                        font.bold: true
                    }
                }
                Rectangle {
                    color: "#f65656"
                    Layout.fillWidth: true
                    Layout.preferredHeight: 30
                    Layout.minimumHeight: 30
                    Layout.maximumHeight: 30
                    border.width: 2
                    border.color: "gray"
                    Label {
                        text: "表情等选择栏"
                        anchors.centerIn: parent
                        font.bold: true
                    }
                }
                Rectangle {
                    color: "#565656"
                    Layout.fillWidth: true
                    Layout.preferredHeight: 100
                    Layout.minimumHeight: 100
                    Layout.maximumHeight: 100
                    border.width: 2
                    border.color: "gray"
                    Label {
                        text: "用户输入信息栏"
                        anchors.centerIn: parent
                        font.bold: true
                    }
                }
                Rectangle {
                    color: "#c65656"
                    Layout.fillWidth: true
                    Layout.preferredHeight: 30
                    Layout.minimumHeight: 30
                    Layout.maximumHeight: 30
                    border.width: 2
                    border.color: "gray"
                    Label {
                        text: "用户发送和关闭栏"
                        anchors.centerIn: parent
                        font.bold: true
                    }
                }
            }
            Rectangle {
                id: inspector
                color: "#565656"
                Layout.fillWidth: true
                Layout.preferredWidth: 200
                Layout.minimumWidth: 200
                Layout.maximumWidth: 200
                border.width: 2
                border.color: "gray"
                Label {
                    text: "右侧好友信息或者群列表栏"
                    anchors.centerIn: parent
                    font.bold: true
                }
            }
        }
    }

}
