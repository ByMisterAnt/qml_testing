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
    signal qmlSignalA
    signal qmlSignalB(string str,int value)

    MouseArea{
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
                 // Тест начинается с клика
                 // Левая кнопка - сигнал передачи Cpp
                 // Щелкните правой кнопкой мыши - сигнал передачи Qml
        onClicked: {
            if(mouse.button===Qt.LeftButton){
                console.log('----clicked left button')
                cpp_obj.name="gongjianbo"
                cpp_obj.year=1992
                                 cpp_obj.sendSignal () // Вызов функции, отмеченной макросом Q_INVOKABLE
            }else{
                console.log('----clicked right button')
                root.qmlSignalA()
                root.qmlSignalB('gongjianbo',1992)
            }
        }
    }

         // Как объект QML
    CppObject{
        id:cpp_obj
                 // Вы также можете работать как собственные объекты QML
        property int counts: 0

        onYearChanged: {
            counts++
            console.log('qml name changed process')
        }
        onCountsChanged: {
            console.log('qml counts changed process')
        }
    }

    Component.onCompleted: {
                 // Способ связывания сигналов и функций обработки сигналов такой же, как и в QML
        //cpp object connect qml object
        cpp_obj.onCppSignalA.connect(function(){console.log('qml signal a process')})
        cpp_obj.onCppSignalB.connect(processB)
        //qml object connect cpp object
        root.onQmlSignalA.connect(cpp_obj.cppSlotA)
        root.onQmlSignalB.connect(cpp_obj.cppSlotB)
    }

    function processB(str,value){
        console.log('qml signal b process',str,value)
    }
}
