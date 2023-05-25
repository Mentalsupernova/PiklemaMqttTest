import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

Window {
    width: 500
    height: 500
    visible: true
    title: qsTr("Mqtt test client")
    color: "#474747"




    GridLayout{
    Connections{
        target : fileReader
        function lineRead(lineContent){
           logger_text.text = logger_text+lineContent
        }
    }
        rows:4
        columns : 1

        Button{
            id: run_btn
            text: "Run"
            width:100
            height:100
            Layout.row:3
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
            color: "white"
            Layout.margins: 5

            Text {
                id: logger_text
                text: "_________LOGER___________\n"
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
            placeholderText: "host"
            placeholderTextColor: "white"
            selectedTextColor: "white"
            color: "#7a7a7a"
            Layout.row: 0
            Layout.margins: 5
        }
        TextField{
            placeholderText: "port"
            placeholderTextColor: "white"
            selectedTextColor: "white"
            color: "#7a7a7a"
            Layout.row: 1
            Layout.margins: 5
        }

        TextField{
            placeholderText: "username"
            placeholderTextColor: "white"
            selectedTextColor: "white"
            color: "#7a7a7a"
            Layout.row: 2
            Layout.margins: 5
        }

        TextField{
            placeholderText: "password"
            placeholderTextColor: "white"
            selectedTextColor: "white"
            color: "#7a7a7a"
            Layout.row: 3
            Layout.margins: 5
        }

        TextField{
            placeholderText: "topic"
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
                id :filedialog
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
            }
        }
}





      }
    }
    }
