import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Rectangle {
    width: 343
    height: 248

    border.width: 2
    border.color: "#000000"

    TabView {
        id: tabView

        anchors.fill: parent

        Tab {
            title: "µÇÂ¼"

            Item {
                Rectangle {
                    id: username

                    anchors.left: parent.left
                    anchors.leftMargin: 41
                    anchors.top: parent.top
                    anchors.topMargin: 27

                    width: 259
                    height: 37

                    border.width: 1
                    border.color: usernameInput.activeFocus ? "#FBA64B" : "#D5D5D5"
                    radius: 4

                    TextInput {
                        id: usernameInput

                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        anchors.right: parent.right
                        anchors.rightMargin: 10
                        anchors.verticalCenter: parent.verticalCenter

                        font.family: "MicroSoft Yahei"
                        font.pointSize: 9

                        color: "#979696"

                        selectByMouse: true
                        selectionColor: "#338FFF"

                        clip: true
						
						activeFocusOnTab: true
                    }

                    Text {
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        anchors.right: parent.right
                        anchors.rightMargin: 10
                        anchors.verticalCenter: parent.verticalCenter

                        font.family: "MicroSoft Yahei"
                        font.pointSize: 9

                        color: "#A9A9A9"

                        text: "username"

                        visible: usernameInput.text || usernameInput.inputMethodComposing ? false : true
                    }

                    MouseArea {
                        anchors.fill: parent
                        acceptedButtons: Qt.NoButton
                        cursorShape: Qt.IBeamCursor
                    }
                }

                Rectangle {
                    id: password

                    anchors.left: username.left
                    anchors.top: username.bottom
                    anchors.topMargin: 10

                    width: 259
                    height: 37

                    border.width: passwordInput.activeFocus ? 3 : 1
                    border.color: passwordInput.activeFocus ? "#A6C8FF" : "#D5D5D5"
                    radius: 4

                    TextInput {
                        id: passwordInput

                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        anchors.right: parent.right
                        anchors.rightMargin: 10
                        anchors.verticalCenter: parent.verticalCenter

                        font.family: "MicroSoft Yahei"
                        font.pointSize: 9

                        color: "#979696"

                        selectByMouse: true
                        selectionColor: "#338FFF"

                        clip: true

                        echoMode: TextInput.Password
						
						activeFocusOnTab: true
                        onAccepted: {
                            console.log("123")
                           _controller.login(usernameInput.text, passwordInput.text)
                        }
                        Component.onCompleted: {
                            console.log("1111111111")

                        }

//                        Keys.onPressed: {
//                            if (event.key == Qt.Key_Enter || event.key == Qt.Key_Return) {
//                                console.log("move left");
//                                event.accepted = true;
//                            }
//                        }
                    }

                    Text {
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        anchors.right: parent.right
                        anchors.rightMargin: 10
                        anchors.verticalCenter: parent.verticalCenter

                        font.family: "MicroSoft Yahei"
                        font.pointSize: 9

                        color: "#A9A9A9"

                        text: "ÃÜÂë"

                        visible: passwordInput.text || passwordInput.inputMethodComposing ? false : true
                    }

                    MouseArea {
                        anchors.fill: parent
                        acceptedButtons: Qt.NoButton
                        cursorShape: Qt.IBeamCursor
                    }
                }

                Image {
                    id: loginIn

                    anchors.left: parent.left
                    anchors.leftMargin: 40
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 25

                    source: "login_button.png"
					
					focus: true
                    activeFocusOnTab: true
					Keys.enabled: true
					
                    MouseArea {
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        onClicked: {
                            loginIn.source = "login_button_2.png"
                            _controller.login(usernameInput.text, passwordInput.text)
                        }
                    }

                    Connections {
                        target: _controller
                        //onErrorRaised: loginIn.source = "login_button.png"
                    }
                }
            }
        }

        style: TabViewStyle {
            tabOverlap: 0
            frameOverlap: 2

            tab: Item {
                implicitWidth: 110
                implicitHeight: 52

                Text {
                    anchors.centerIn: parent

                    font.family: "MicroSoft Yahei"
                    font.pointSize: 15

                    color: styleData.selected ? "#FFAF15" :"#555555"

                    text: styleData.title
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    acceptedButtons: Qt.NoButton
                }

                Rectangle {
                    anchors.left: parent.left
                    anchors.leftMargin: 2
                    anchors.right: parent.right
                    anchors.rightMargin: 2
                    anchors.bottom: parent.bottom
                    height: 2

                    color: styleData.selected ? "#FFAF15" : "#555555"

                    visible: styleData.selected
                }
            }

            frame: Item {
                Rectangle {
                    anchors.left: parent.left
                    anchors.leftMargin: 2
                    anchors.right: parent.right
                    anchors.rightMargin: 2
                    anchors.top: parent.top
                    height: 2

                    color: "#E9E9E9"
                }
            }
        }
    }

    Image {
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 24

        source: "login_close.png"

        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            onClicked: _controller.cancel()
        }
    }

    Rectangle {
        id: alert

        width: 238
        height: 45

        color: "#E78302"

        anchors.centerIn: parent

        visible: false

        Text {
            id: alertText

            color: "#FFFFFF"

            font.family: "Microsoft Yahei"
            font.pointSize: 10

            anchors.centerIn: parent
        }
    }

    Timer {
        id: timer
        interval: 1000
    }

    Connections {
        target: _controller
    }

    Connections {
        target: timer
        onTriggered: alert.visible = false
    }
}
