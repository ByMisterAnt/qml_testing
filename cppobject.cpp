//file CppObject.cpp
#include "cppobject.h"
#include <QDebug>
#include <QString>
CppObject::CppObject(QObject *parent)
    : QObject(parent),myName("nobne"),myYear(0)
{
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(readData()));

    timer->start(3000);
}

void CppObject::readData()
{
myName = "ff";
}

QString CppObject::getName() const
{
    //myName = QString::number(1);

return myName;
}



