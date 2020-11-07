import QtQuick 2.9
import Theme 1.0

Rectangle {
    height: 65 * Theme.scaleH
    width: parent.width
    border.color: "black"

    Text {
        text: qsTr("Demo POS")
        font.bold: true
        font.pointSize: 16
        font.family: "Roboto"
        anchors.left: parent.left
        anchors.leftMargin: 10 * Theme.scaleW
        anchors.verticalCenter: parent.verticalCenter
    }

    Row {
        height: parent.height
        anchors.centerIn: parent
        CustomFlatButton {
            width: 120 * Theme.scaleW
            height: parent.height
            text: qsTr("View")
        }
        CustomFlatButton {
            width: 120 * Theme.scaleW
            height: parent.height
            text: qsTr("Order")
        }
    }

    CustomFlatButton {
        width: height
        height: parent.height
        text: qsTr("\u2716")
        anchors.right: parent.right
        onClicked: Qt.quit()
    }
}
