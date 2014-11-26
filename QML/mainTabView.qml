import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.2
ApplicationWindow {
    width: 800
    height: 880
    visible: true
    id: screen
    property int numTabs: 5
    property int margin: 2
    property string transparentColor : "transparent"
    property string redColor: "red"
    property string grayColor: "#B7B9BC" // "lightgray"

Rectangle {
    id: backRect
    radius: 10
    width: parent.width
    height: parent.height
    color: grayColor
    anchors.top: parent.top
    anchors { leftMargin: 10; bottomMargin: 10; topMargin: 10; rightMargin:10 }

Rectangle{
    id: tabsRect
    radius: 10
    width: parent.width
    height: 80
    anchors.top: parent.top
    Row{
        id:tabsRow
        width: parent.width
        height: parent.height
        anchors.fill: parent
        function clearState()
        {
            var j=1;
            for(j=0;j<= numTabs-1;j++)
            {
                children[j].isSelected = false;
                children[j].state = "unselected";
                children[j].applyState();
            }
        }

        CustomTab{
            id: customTab0
            ctlWidth: parent.width/numTabs
            ctlHeight: parent.height - margin
            tabIndex: 0
            isSelected: false;
            iPosition: 0
            //anchors { left: parent.left; bottom: parent.bottom; bottomMargin: margin }
        }

        CustomTab{
            id: customTab1
            ctlWidth: parent.width/numTabs-margin
            ctlHeight: parent.height - margin
            tabIndex: 1
            isSelected: false;
            iPosition: 1
            //anchors { left: customTab0.right; bottom: parent.bottom; leftMargin: margin; bottomMargin: margin; }
        }

        CustomTab{
            id: customTab2
            ctlWidth: parent.width/numTabs-margin
            ctlHeight: parent.height - margin
            tabIndex: 2
            isSelected: false;
            iPosition: 1
            //anchors { left: customTab1.right; bottom: parent.bottom; leftMargin: margin; bottomMargin: margin; }
        }

        CustomTab{
            id: customTab3
            ctlWidth: parent.width/numTabs-margin
            ctlHeight: parent.height - margin
            tabIndex: 3
            isSelected: false;
            iPosition: 1
            //anchors { left: customTab2.right; bottom: parent.bottom; leftMargin: margin; bottomMargin: margin; }
        }

        CustomTab{
            id: customTab4
            ctlWidth: parent.width/numTabs-margin
            ctlHeight: parent.height - margin
            tabIndex: 4
            isSelected: false;
            iPosition: 2
            //anchors { left: customTab3.right; bottom: parent.bottom; leftMargin: margin; bottomMargin: margin; }
        }
      }
    }
  }
}
