import QtQuick 2.0
import Theme 1.0

Item {
    Column {
        spacing: 25 * Theme.scale
        anchors.centerIn: parent

        Text {
            text: qsTr("<b>Modern POS</b>")
            font.pointSize: 20 * Theme.scale
            anchors.horizontalCenter: parent.horizontalCenter
        }

        AnimatedImage {
            width: 300 * Theme.scaleW
            height: 300 * Theme.scaleH
            source: "qrc:/images/startup.gif"
        }
    }

    Timer {
        id: timerId
        running: false
        repeat: false
        interval: 1500
        onTriggered: appmanager.startupDone()
    }

    Component.onCompleted: timerId.start()
}
