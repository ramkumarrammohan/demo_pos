import QtQuick 2.9
import QtGraphicalEffects 1.0
import Theme 1.0

Item {
    id: card

    property bool categoryButton: true
    property string name: ""
    property double price: 0.00
    property string currency: "\u20B9"

    signal tapped()

    Rectangle {
        id: background
        anchors.fill: parent
        color: "#FFFFFF"
        radius: 10 * Theme.scale

        Column {
            spacing: 5
            width: parent.width
            anchors.centerIn: parent

            Text {
                text: qsTr("<b>%1</b>").arg(name)
                color: "#000000"
                width: parent.width - 20
                font.pointSize: 15 * Theme.scale
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                font.family: "Roboto"
                verticalAlignment: Qt.AlignVCenter
                horizontalAlignment: Qt.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }
            Text {
                visible: !categoryButton
                text: qsTr("%2%3").arg(currency).arg(price)
                color: "#000000"
                width: parent.width - 20
                font.pointSize: 11 * Theme.scale
                wrapMode: Text.WordWrap
                font.family: "Roboto"
                verticalAlignment: Qt.AlignVCenter
                horizontalAlignment: Qt.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }

    layer.enabled: true
    layer.effect: DropShadow {
        source: card
        radius: 10 * Theme.scale
        samples: 8
        color: "#D3D3D3"
        verticalOffset: 2
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        enabled: card.enabled

        onPressed: {
            background.color = "#F5F5F5"
        }

        onReleased: {
            background.color = "#FFFFFF"
            tapped()
        }
    }
}
