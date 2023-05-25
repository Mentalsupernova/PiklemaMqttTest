import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Dialogs
import QtQuick 2.15
import QtQuick.Controls 2.15

Window {
    id: win

    color: "#474747"
    height: 500
    title: qsTr("Mqtt test client")
    visible: true
    width: 500

    ListModel {
        id: loggerModel

    }

    Connections {
        function onMessageLogged(message) {
            listView.model.append({
                    "message": message
                });
            listView.positionViewAtEnd();
        }

        target: Logger
    }
    GridLayout {
        columns: 1
        rows: 4

        Button {
            id: run_btn

            Layout.row: 3
            height: 100
            text: "Run"
            width: 100

            onClicked: {
                fileReader.ReadFileCommand(filePath.text)
            }

        }

        ProgressBar{ id: bar
            //from: 0
            //to:100
            //width: win.width-20
            width: Window.width

            height: 50
            Layout.row: 1
            Layout.margins: 5
        }

        Rectangle {
            id: logs

            Layout.margins: 5
            Layout.row: 2
            height: Window.height - (bar.height + options.height) - run_btn.height
            width: Window.width

            ListView {
                id: listView

                anchors.fill: parent
                model: loggerModel

                delegate: Text {
                    text: modelData
                }
            }
        }
        GridLayout {
            id: options

            Layout.row: 0
            columns: 2

            GridLayout {
                id: fields

                Layout.column: 0
                rows: 7

                TextField {
                    id: host

                    Layout.margins: 5
                    Layout.row: 0
                    color: "#7a7a7a"
                    placeholderText: "host"
                    placeholderTextColor: "white"
                    selectedTextColor: "white"
                    text: ""
                }
                TextField {
                    id: port

                    Layout.margins: 5
                    Layout.row: 1
                    color: "#7a7a7a"
                    placeholderText: "port"
                    placeholderTextColor: "white"
                    selectedTextColor: "white"
                    text: ""
                }
                TextField {
                    id: username

                    Layout.margins: 5
                    Layout.row: 2
                    color: "#7a7a7a"
                    placeholderText: "username"
                    placeholderTextColor: "white"
                    selectedTextColor: "white"
                    text: ""
                }
                TextField {
                    id: password

                    Layout.margins: 5
                    Layout.row: 3
                    color: "#7a7a7a"
                    placeholderText: "password"
                    placeholderTextColor: "white"
                    selectedTextColor: "white"
                    text: ""
                }
                TextField {
                    id: topic

                    Layout.margins: 5
                    Layout.row: 4
                    color: "#7a7a7a"
                    placeholderText: "topic"
                    placeholderTextColor: "white"
                    selectedTextColor: "white"
                    text: ""
                }
                GridLayout {
                    Layout.row: 6
                    columns: 2

                    TextField {
                        id: filePath

                        Layout.column: 0
                        Layout.margins: 5
                        color: "#7a7a7a"
                        placeholderText: "chose file"
                        placeholderTextColor: "white"
                        selectedTextColor: "white"
                    }
                    Button {
                        Layout.column: 1
                        Layout.margins: 5
                        height: 100
                        text: "chose file"
                        width: 100

                        onClicked: fileDialog.open()

                    }
                    FileDialog {
                        id: fileDialog

                        title: "Please choose a file"

                        onAccepted: {
                            var selectedFile = fileDialog.currentFile;
                            filePath.text = selectedFile;
                            console.log("Selected file: " + selectedFile);
                        }
                        onRejected: {
                            Logger.log("Error, file path is empty");
                        }
                    }
                }
            }
        }
    }
}
