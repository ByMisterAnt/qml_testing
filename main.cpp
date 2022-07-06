//file main.cpp
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "CppObject.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

         // qmlRegisterType регистрирует тип C ++ в QML
         // arg1: имя модуля при импорте
         // arg2: номер основной версии
         // arg3: дополнительный номер версии
         // arg4: имя типа QML
    qmlRegisterType<CppObject>("MyCppObject",1,0,"CppObject");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
