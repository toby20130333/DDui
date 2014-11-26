import QtQuick 2.0

Rectangle {

    id: customTab
    clip: true
    property int ctlWidth;
    property int ctlHeight;
    property int redLineHeight: 20;
    property bool isSelected;
    property bool isHighlighted;
    property int tabIndex;
    property int iPosition; // 0 = left; 1 = middle; 2 = right

    width: ctlWidth
    height: ctlHeight
    color:  "#B7B9BC"
    radius: 10

    function applyHeights(customTabHeight, topHeight, bottomHeight)
    {
        customTab.height = customTabHeight

        elements.children[0].height = topHeight
        elements.children[1].height = topHeight
        elements.children[2].height = bottomHeight
        elements.children[3].height = bottomHeight
    }

    function clearChildState()
    {
        applyHeights(ctlHeight, redLineHeight, ctlHeight - redLineHeight)
    }

    function getCorrectColor()
    {
        if(isSelected)
        {
            return transparentColor;
        }
        else if(isHighlighted)
        {
            return redColor;
        }
        else
        {
            return grayColor;
        }
    }

    function applyState()
    {
        if(isSelected)
        {
            applyHeights(ctlHeight + redLineHeight/2, redLineHeight, ctlHeight + redLineHeight/2)
            customTab.color=redColor
        }
        else if(isHighlighted)
        {
            applyHeights(ctlHeight, redLineHeight/2, ctlHeight)
            customTab.color = redColor
        }
        else
        {
            applyHeights(ctlHeight, redLineHeight, ctlHeight)
            customTab.color=grayColor
        }

        if(iPosition == "0")
        {
            elements.children[0].color = transparentColor;
            elements.children[1].color = getCorrectColor();
        }
        else if(iPosition == "1")
        {
            elements.children[0].color = getCorrectColor();
            elements.children[1].color = getCorrectColor();
        }
        else if(iPosition == "2")
        {
            elements.children[0].color = getCorrectColor();
            elements.children[1].color = transparentColor;
        }
    }

    Component.onCompleted: {
            applyState();
        }

    Grid{
        id:elements
        width: parent.width
        height: parent.height
        columns: 2
        rows: 2
        Rectangle{id: topLeft; color: grayColor; width: parent.width/2; height: redLineHeight;}
        Rectangle{id: topRight; color: grayColor; width: parent.width/2; height: redLineHeight;}
        Rectangle{id: bottomLeft; color: grayColor; width: parent.width/2; height: parent.height - redLineHeight;}
        Rectangle{id: bottomRight; color: grayColor; width: parent.width/2; height: parent.height - redLineHeight;}
    }

    MouseArea{
        hoverEnabled: true
        anchors.fill: parent
        onClicked: {
            parent.parent.clearState();
            parent.isSelected = true;
            parent.state = "selected"
            parent.applyState();
        }
        onEntered: {
            parent.isHighlighted = true;
            if(!parent.isSelected)
            {
                parent.applyState();
            }
        }
        onExited: {
            parent.isHighlighted = false;
            if(!parent.isSelected)
            {
                parent.applyState();
            }
        }
    }
    states: [
        State {
            name: "selected"
            PropertyChanges { target: customTab; anchors.bottomMargin: 0}
        },

        State {
            name: "unselected"
            PropertyChanges {target:customTab; anchors.bottomMargin: margin}
        }
    ]
}
