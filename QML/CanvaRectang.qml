import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Window 2.0
import QtQuick.Controls.Styles 1.1
import QtGraphicalEffects 1.0

Item {
    id:mainRect
    width: 72
    height: 72
    property string canvasimg: "file:///D:/Users/Administrator/WebstormProjects/QtClub/nodeclub/public/images/128.png"
    property color mystroke: "#FFC830"
    Image {
        id: orgImg
        source:canvasimg// This is available in all editors.
        visible: false
    }
    Item{
        id:chilrdItem
        width: 72
        height: 72
        anchors.centerIn: parent
        Canvas {
            id: canvas
            width: chilrdItem.width; height: chilrdItem.height
            property real hue: 0.0
            onPaint: {
                var ctx = getContext("2d")
                ctx.lineWidth = 4
                ctx.strokeStyle = mystroke
                // setup the fill
                ctx.fillStyle = "#00ffffff"
                // begin a new path to draw
                ctx.beginPath()
                // top-left start point
                ctx.moveTo(3,0)
                // upper line
                ctx.lineTo(chilrdItem.width-3,0)
                ctx.lineTo(chilrdItem.width,3)
                // right line
                ctx.lineTo(chilrdItem.width,chilrdItem.width-3)
                ctx.lineTo(chilrdItem.width-3,chilrdItem.width)
                ctx.lineTo(3,chilrdItem.width);
                ctx.lineTo(0,chilrdItem.width-3);
                ctx.lineTo(0,3)
                // bottom line
//                ctx.lineTo(0,chilrdItem.width)
                // left line through path closing
                ctx.closePath()
                ctx.clip()
                // fill using fill style
                ctx.fill()
                // stroke using line width and stroke style
                ctx.stroke()
                ctx.drawImage(canvasimg, getXY(true), getXY(false))
                // draw stroke around path
                ctx.closePath()
                ctx.stroke()
                // restore previous setup
                ctx.restore()
            }
            Component.onCompleted: {
                loadImage(canvasimg);
                repaintUI();
            }
        }

    }function repaintUI()
    {
        canvas.requestPaint();
    }
    function getXY(isXS)
    {
        var tmp;
        if(orgImg.sourceSize.width == chilrdItem.width && orgImg.sourceSize.height == chilrdItem.height)
        {
             tmp =[0,0]
        }else if(orgImg.sourceSize.width < chilrdItem.width && orgImg.sourceSize.height <chilrdItem.height)
        {
             tmp =[(chilrdItem.width-orgImg.sourceSize.width)/2,(chilrdItem.height-orgImg.sourceSize.height)/2];
        }else{
             tmp =[(chilrdItem.width-orgImg.sourceSize.width)/2,(chilrdItem.height-orgImg.sourceSize.height)/2];
        }
        console.log("x y array "+tmp+"\n"+orgImg.sourceSize.width);
        if(isXS)
        {
            return tmp[0];
        }else{
            return tmp[1];
        }
    }
}
