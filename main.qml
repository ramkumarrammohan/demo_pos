import QtQuick 2.9
import QtQuick.Controls 2.2

import Theme 1.0
import QMLEnums 1.0

import "items"

ApplicationWindow {
    id: appWinId
    width: 640
    height: 480
    visible: appmanager.status !== AppStatus.Unknown

    header: AppHeader{}

    StackView {
        id: stackViewId
        anchors.fill: parent
    }

    Component {
        id: startupScreenComponentId
        StartUpScreen {
            id: startupScreenId
        }
    }

    Component {
        id: menuscreenComponentId
        MenuScreen {
        }
    }

    Component.onCompleted: {
        stackViewId.push(startupScreenComponentId)
        appWinId.showFullScreen()
    }

    Connections {
        target: appmanager
        onStatusChanged: {
            if(status == AppStatus.Ready)
            {
                stackViewId.pop()
                stackViewId.push(menuscreenComponentId)
            }
        }
    }
}
