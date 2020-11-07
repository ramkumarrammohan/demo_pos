import QtQuick 2.9
import QtQuick.Controls 2.2
import Theme 1.0

Button {
    property color color: Theme.backgroundColor

    font.bold: true
    font.pointSize: 12 * Theme.scale
    font.family: "Roboto"

    background: Rectangle {
        height: parent.height
        width: parent.width
        color: parent.color
        border.color: "#000000"
    }
}
