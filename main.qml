//file main.qml
import QtQuick 2.9
import QtQuick.Window 2.2
 // Представляем наш зарегистрированный модуль
import MyCppObject 1.0

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    color:"green"
    signal qmlSignalB(string str,int value)
    Text {
        id: lolkek
        text: qsTr("text")
    }
    MouseArea{
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
                 // Тест начинается с клика
                 // Левая кнопка - сигнал передачи Cpp
                 // Щелкните правой кнопкой мыши - сигнал передачи Qml
        onClicked: {
            if(mouse.button===Qt.LeftButton){
                lolkek.text = cpp_obj.name
                //cpp_obj.sendSignal () // Вызов функции, отмеченной макросом Q_INVOKABLE
            }

        }
    }
    Timer
        {
            interval: 500; running: true; repeat: true
            onTriggered: lolkek.text = cpp_obj.name + "Время: " + new Date().toTimeString()
        }
         // Как объект QML
    CppObject{
        id:cpp_obj
                 // Вы также можете работать как собственные объекты QML
        property int counts: 0


    }

    Component.onCompleted: {
                 // Способ связывания сигналов и функций обработки сигналов такой же, как и в QML
        //cpp object connect qml object
        cpp_obj.onCppSignalB.connect(processB)
        //qml object connect cpp object
    }

    function processB(str,value){
        console.log('qml signal b process',str,value)
    }
}
