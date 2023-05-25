import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Dialogs
import QtQuick 2.15
import QtQuick.Controls 2.15


Window {
    width: 500
    height: 500
    visible: true
    title: qsTr("Mqtt test client")
    color: "#474747"


    ListModel {
        id: loggerModel
    }

    Connections {
        target: Logger
        function onMessageLogged(message) {

            listView.model.append({"message":message})
            listView.positionViewAtEnd()
        }
    }

    GridLayout{
        rows:4
        columns : 1

        Button{
            id: run_btn
            text: "Run"
            width:100
            height:100
            Layout.row:3
            onClicked: fileReader.ReadFileCommand(filePath.text)
        }

        ProgressBar{
            id: bar
            from: 0
            to:100
            width: Window.width
            height: 50
            Layout.row: 1
            Layout.margins: 5
        }

        Rectangle {
            id:logs
            Layout.row:2
            width: Window.width
            height : Window.height - (bar.height + options.height) -run_btn.height
            Layout.margins: 5

        ListView {
            id: listView
            anchors.fill: parent
            model: loggerModel

            delegate: Text {
                text: modelData
            }
        }
        }

    GridLayout{
        Layout.row: 0
        columns: 2


        id: options
GridLayout{



    id: fields
    Layout.column: 0
        rows: 7
        TextField{
            id : host
            placeholderText: "host"
            text:""
            placeholderTextColor: "white"
            selectedTextColor: "white"
            color: "#7a7a7a"
            Layout.row: 0
            Layout.margins: 5
        }
        TextField{
            id : port
            placeholderText: "port"
            text:""
            placeholderTextColor: "white"
            selectedTextColor: "white"
            color: "#7a7a7a"
            Layout.row: 1
            Layout.margins: 5
        }

        TextField{
            id : username
            placeholderText: "username"
            text:""
            placeholderTextColor: "white"
            selectedTextColor: "white"
            color: "#7a7a7a"
            Layout.row: 2
            Layout.margins: 5
        }

        TextField{
            id : password
            placeholderText: "password"
            text:""
            placeholderTextColor: "white"
            selectedTextColor: "white"
            color: "#7a7a7a"
            Layout.row: 3
            Layout.margins: 5
        }

        TextField{
            id : topic
            placeholderText: "topic"
            text:""
            placeholderTextColor: "white"
            selectedTextColor: "white"
            color: "#7a7a7a"
            Layout.row: 4
            Layout.margins: 5
        }
        GridLayout{


            Layout.row: 6
            columns: 2
            TextField{
            id:filePath
            placeholderText: "chose file"
            placeholderTextColor: "white"
            selectedTextColor: "white"
            color: "#7a7a7a"
                Layout.margins: 5
                Layout.column: 0

            }
            Button{
                text: "chose file"
                width:100
                height:100
                Layout.column: 1
                Layout.margins: 5
                onClicked: fileDialog.open()
            }
            FileDialog {
                id: fileDialog
                title: "Please choose a file"
                onAccepted: {

                    var selectedFile = fileDialog.currentFile
                    filePath.text = selectedFile
                    console.log("Selected file: " + selectedFile)

                }
                onRejected: {
                    Logger.log("Error, file path is empty")
                }
            }
        }
}





      }
    }
    }
