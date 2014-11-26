import QtQuick 2.0
import QtQuick.Controls 1.2

Item {
  id: root
  width: parent.width //继承父组建的宽度
  height: 60

  property alias text: textitem.text //变量
  signal clicked
  //透明矩形，点击的时候可见
  Rectangle {
    anchors.fill: parent//描点充满父组建
    color: "#11ffffff"//透明
    visible: mouse.pressed//点击可见
  }
  //文本
  Text {
    id: textitem
    color: "white"//字体颜色
    font.pixelSize: 24//字体大小
    text: modelData//显示的文字
    anchors.verticalCenter: parent.verticalCenter//父组件垂直居中
    anchors.left: parent.left//靠左
    anchors.leftMargin: 30//左边距
  }
  //黑色矩形
  Rectangle {
    anchors.left: parent.left//描点位置为父组建左侧
    anchors.right: parent.right//右侧
    anchors.margins: 15//外边距
    height: 1//高
    color: "#424246"//黑色
  }
  //图片
  Button {
    anchors.right: parent.right//父组建描点
    anchors.rightMargin: 20//右边距20
    anchors.verticalCenter: parent.verticalCenter//垂直居中
    height: 30
    width: 80
    text: "进入..."//图片路径
  }
  //点击响应
  MouseArea {
    id: mouse
    anchors.fill: parent//描点充满整个父组建
    onClicked: root.clicked()//父组建点击响应

  }
}
