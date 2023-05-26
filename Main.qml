import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Dialogs
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtCharts
Window {
    id: win

    color: "#474747"
    height: 520
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
            Layout.margins:10

            onClicked: {
                if(fileReader.ReadFileCommand(filePath.text)){

                mqttClient.connectToBroker(host.text,parseInt(port.text))
                mqttClient.publishMessage(topic.text,fileReader.getLines(),username.text,password.text)
                }else{
                    Logger.log("Error,something goes wrong")
                }

            }

        }


        Rectangle {
            id: logs

            Layout.topMargin : 20
            Layout.row: 2
            height: 200
            width: Window.width
            color : "#575352"
            ListView {
                id: listView

                anchors.fill: parent

                model: loggerModel

                delegate: Rectangle	{
                    Layout.topMargin: 10
                    width : parent.width - 10
                    height : 20
                    color: "#4d4573"
                    Text{
                        color :"white"
                        text: modelData
                    }

                }
            }
        }
        GridLayout {
            id: options

            Layout.row: 0
            columns: 2

            GridLayout{
                Layout.column : 1
                columns:2

            Label{
                Layout.column: 0
                text:"Line counter"
            }
                TextField{
                    Layout.column : 1

                text:"0"
            }

            }


            GridLayout {
                id: fields

                Layout.column: 0
                rows: 7

                TextField {
                    id: host

                    Layout.margins: 5
                    Layout.row: 0
                    //color: "#7a7a7a"
                    color: "white"
                    placeholderText: "host"
                    placeholderTextColor: "white"
                    selectedTextColor: "white"
                    text: "test.mosquitto.org"

                }
                TextField {
                    id: port

                    Layout.margins: 5
                    Layout.row: 1
                    color: "white"
                    placeholderText: "port"
                    placeholderTextColor: "white"
                    selectedTextColor: "white"
                    text: "1883"
                }
                TextField {
                    id: username

                    Layout.margins: 5
                    Layout.row: 2
                    color: "white"
                    placeholderText: "username"
                    placeholderTextColor: "white"
                    selectedTextColor: "white"
                    text: ""
                }
                TextField {
                    id: password

                    Layout.margins: 5
                    Layout.row: 3
                    color: "white"
                    placeholderText: "password"
                    placeholderTextColor: "white"
                    selectedTextColor: "white"
                    text: ""
                }
                TextField {
                    id: topic

                    Layout.margins: 5
                    Layout.row: 4
                    color: "white"
                    placeholderText: "topic"
                    placeholderTextColor: "white"
                    selectedTextColor: "white"
                    text: "test/topic"
                }
                GridLayout {
                    Layout.row: 6
                    columns: 2

                    TextField {
                        id: filePath

                        Layout.column: 0
                        Layout.margins: 5
                        color: "white"
                        placeholderText: "chose file"
                        placeholderTextColor: "white"
                        selectedTextColor: "white"
                    }
                    Button {
                        Layout.column: 1
                        Layout.margins: 5
                        height: 100
                        text: "choose file"
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
