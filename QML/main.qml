import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Window 2.0
import QtQuick.Controls.Styles 1.1

Item {
    id:main
    visible: true
    width: 640
    height: 480
//    title: qsTr("Hello World")
    onWidthChanged: {
        console.log("salkalk--------->"+main.width);
        setValue(sld.value);
    }
    FontLoader {
        id: mainFont;
        //source: "../../manteka.ttf"
        //source: "file:///D:/TobyYi/yibansvn/YbTestDemo/RepeaterQml/HELVETICANEUELTPRO-THEX.OTF"
    }

//    Gradientqml{
//        id:xx
//        anchors.fill: parent
//    }
//    TableViewDemo{
//        id:xx
//        anchors.fill: parent
//    }

    Text {
        id:perenOf
        text: "0%"
        horizontalAlignment: Text.AlignHCenter
        font.family: mainFont.name;
        font.pointSize: 14;
        x:battey.x-50
        y:battey.y+battey.height/2
    }

    Rectangle{
        id:battey
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        width: 22
        height: main.height/2
        //        color: "#00ffffff"
        border.width: 2
        border.color: "gray"
        rotation: 180
        radius: 5
        property color oneColor: "lightsteelblue"
        property color twoColor: "blue"
        property color thirdColor: "blue"
        gradient: Gradient {
            GradientStop { position: 1.0; color: battey.oneColor }
            GradientStop { position: 0.5; color: battey.twoColor}
            GradientStop { position: 0.0; color: battey.thirdColor}
        }
        Column{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 2
            Repeater{
                id:rp
                model: 0
                property color rpColor: "green"
                property int rpHeight: 10
                Item{
                    id:line
                    width: 20
                    height: rp.rpHeight
                    property color myColor: rp.rpColor
                    Rectangle{
                        id:line1
                        width: 18
                        height: 2
                        anchors.centerIn: parent
                        color: line.myColor
                    }
                }
            }
        }
    }
    function setValue(value)
    {
        if(value<=0.2)
        {
            rp.rpColor = "green";
            rp.rpHeight= 10;
        }else if(value >0.2 && value <=0.4)
        {
            rp.rpColor = "#147975";
            rp.rpHeight= 8;
        }else if(value >0.4 && value <=0.6){
            rp.rpColor = "#49A9E3";
            rp.rpHeight= 6;
        }else if(value >0.6 && value <=0.8){
            rp.rpColor = "#B9466D";
            rp.rpHeight= 4;
        }else{
            rp.rpColor = "red";
            rp.rpHeight= 3;
        }

        rp.model = ((battey.height-6)/rp.rpHeight)*(value);
    }
    property double iiii: 0.05
    Timer {
        id:ti
        interval: 1000; running: true; repeat: true
        onTriggered: setValues()
    }

    function setValues()
    {
        console.log("iiiiiiiiiiiiiii "+iiii)
        if(iiii > 0.9){
            setValue(1.0);
            sld.value = 1.0;
            ti.stop();
            return;
        }
        iiii +=0.1;
        setValue(iiii);
        sld.value = iiii;
    }

    Slider{
        id:sld
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        width: 200
        height: 10
        value: 0.0
        style: SliderStyle {
            groove: Rectangle {
                implicitWidth: 200
                implicitHeight: 10
                color: "gray"
                radius: 8
            }
            handle: Rectangle {
                anchors.centerIn: parent
                color: control.pressed ? "white" : "lightgray"
                border.color: "gray"
                border.width: 2
                width: 20
                height: 20
                radius: 10
            }
        }
        maximumValue: 1
        minimumValue: 0
        onValueChanged: {
            console.log(" 0000000 "+sld.value);
            setValue(sld.value);
            perenOf.text =Math.ceil(sld.value*100)+"%"
        }
    }
}
