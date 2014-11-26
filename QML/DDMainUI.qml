import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

StackView {
    id: stackView
    anchors.fill: parent
    width: 480
    height: 720

    ListModel{
        id:pageModel
        ListElement{
            title:"Hi DDZJZ"
        }
    }
    Button{
        id:add
        width: 100
        height: 40
        text:"添加"
        onClicked: {
                //stackView.push(Qt.resolvedUrl(LoginUI{}))
        }
    }

    delegate: StackViewDelegate {
        function transitionFinished(properties)
        {
            properties.exitItem.opacity = 1
        }
         pushTransition: StackViewTransition {
            PropertyAnimation {
                target: enterItem
                property: "opacity"
                from: 0
                to: 1
                duration: 1000
            }
            PropertyAnimation {
                target: exitItem
                property: "opacity"
                from: 1
                to: 0
                duration: 1000
            }
        }
    }
    initialItem: Item {
        width: parent.width
        height: parent.height
        ListView {
            model: pageModel
            anchors.fill: parent
            delegate: Text {
                text: title
                //onClicked: stackView.push(Qt.resolvedUrl(page))
            }
        }
    }
}
