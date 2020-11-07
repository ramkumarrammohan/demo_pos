import QtQuick 2.9
import Theme 1.0
import QMLEnums 1.0
import "items"

Item {
    property variant order: null

    Row {
        spacing: 0
        anchors.fill: parent

        Item {
            height: parent.height
            width: parent.width - basketItemId.width - seperatorId.width

            Flow {
                spacing: 25 * Theme.scale
                anchors.fill: parent
                anchors.margins: 25 * Theme.scale
                anchors.horizontalCenter: parent.horizontalCenter

                Repeater {
                    id: categoryRepeaterId
                    model: actionCenter.categories
                    delegate: MenuButton {
                        name: item.name
                        width: 150 * Theme.scaleW
                        height: 150 * Theme.scaleH
                        onTapped: {
                            actionCenter.selectedCategory(item.id)
                        }
                    }
                }

                Rectangle {
                    id: menuSeparatorId
                    height: 1
                    width: parent.width
                    color: "#D3D3D3"
                }

                Repeater {
                    id: itemRepeaterId
                    model: actionCenter.items
                    delegate: MenuButton {
                        name: item.name
                        price: item.price
                        categoryButton: false
                        width: 150 * Theme.scaleW
                        height: 150 * Theme.scaleH
                        onTapped: newOrder.addOrderItem(item)
                    }
                }
            }
        }

        Rectangle {
            id: seperatorId
            width: 1
            height: parent.height
            color: "#D3D3D3"
        }

        Item {
            id: basketItemId
            height: parent.height
            width: parent.width * 0.25

            Column {
                spacing: 10 * Theme.scale
                anchors.fill: parent
                anchors.margins: 10 * Theme.scale

                Item {
                    id: checkoutAreaItemId
                    width: parent.width
                    height: 100 * Theme.scaleH
                    Row {
                        anchors.fill: parent
                        Rectangle {
                            height: parent.height
                            width: parent.width / 2
                            border.color: "#000000"
                            Text {
                                anchors {
                                    left: parent.left
                                    top: parent.top
                                    topMargin: 10 * Theme.scaleH
                                    leftMargin: 10 * Theme.scaleW
                                }
                                text: qsTr("Total")
                            }
                            Text {
                                id: totalAmountTextId
//                                text: actionCenter.newOrder.totalAmount
                                text: qsTr("\u20B9 %1").arg(newOrder.totalAmount)
                                anchors.fill: parent
                                font.bold: true
                                font.pointSize: 15 * Theme.scale
                                font.family: "Roboto"
                                verticalAlignment: Text.AlignVCenter
                                horizontalAlignment: Text.AlignHCenter
                            }
                        }
                        CustomFlatButton {
                            height: parent.height
                            width: parent.width / 2
                            text: qsTr("Checkout")
                            font.pointSize: 15 * Theme.scale
                            onClicked: actionCenter.checkout()
                        }
                    }
                }

                ListView {
                    id: newOrderListViewId
                    width: parent.width
                    height: parent.height - parent.spacing - checkoutAreaItemId.height
                    model: newOrder.orderItems
                    delegate: Item {
                        height: 50 * Theme.scaleH
                        width: parent.width
                        Text {
                            text: qsTr("%1 x %2").arg(item.quantity).arg(item.name)
                            width: parent.width * 0.75
                            height: parent.height
                            anchors.left: parent.left
                            verticalAlignment: Text.AlignVCenter
                            font.bold: true
                            font.pointSize: 11
                            font.family: "Roboto"
                        }
                        Text {
                            text: qsTr("%1").arg(item.price.toFixed(2))
                            width: parent.width * 0.25
                            height: parent.height
                            anchors.right: parent.right
                            horizontalAlignment: Text.AlignRight
                            verticalAlignment: Text.AlignVCenter
                            font.bold: true
                            font.pointSize: 11
                            font.family: "Roboto"
                        }
                    }
                }
            }

        }
    }

//    Connections {
//        target: appmanager
//        onStatusChanged: {
//            if(status == AppStatus.Ready)
//            {
//                categoryRepeaterId.model = actionCenter.categories
//                itemRepeaterId.model = actionCenter.items
//                newOrderListViewId.model = actionCenter.newOrder.orderItems
////                totalAmountTextId.text = newOrder.checkoutPrice
//            }
//        }
//    }

//    onOrderChanged: {
//        console.log("===")
//        if(order)
//            totalAmountTextId.text = order.totalAmount
//    }
}
