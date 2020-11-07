import QtQuick 2.9
import QtQuick.Window 2.3

pragma Singleton

QtObject {
    id: myTheme

    property int refWidth
    property int refHeight
    property real scaleW
    property real scaleH
    property real scale

    // app colors
    property color primaryColor
    property color secondaryColor
    property color backgroundColor

    Component.onCompleted: {
        myTheme.refWidth = 1920;
        myTheme.refHeight = 1200;
        myTheme.scaleW = (Screen.width/refWidth);
        myTheme.scaleH = (Screen.height/refHeight);
        myTheme.scale = myTheme.scaleH > myTheme.scaleW ? myTheme.scaleH :
                                                           myTheme.scaleW

        myTheme.primaryColor = ""
        myTheme.secondaryColor = ""
        myTheme.backgroundColor = "#FFFFFF"

        console.log("PixelDensity(number of physical pixels/millimeter):"+
                    Screen.pixelDensity+", ("+Screen.width+", "+Screen.height+")")
        console.log("(ScaleH, ScaleW)):" + " ("+scaleW+", "+scaleH+")")
    }
}
