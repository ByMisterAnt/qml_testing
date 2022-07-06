//file CppObject.cpp
#include "CppObject.h"
#include <QDebug>

CppObject::CppObject(QObject *parent)
    : QObject(parent),myName("none"),myYear(0)
{

}

void CppObject::sendSignal()
{
         // Для тестирования отправляем сигнал после вызова этой функции
    qDebug()<<"cpp sendSignal method";
    emit cppSignalA();
    emit cppSignalB(myName,myYear);
}

void CppObject::setName(const QString &name)
{
    qDebug()<<"cpp setName"<<name;
    myName=name;
}

QString CppObject::getName() const
{
    qDebug()<<"cpp getName";
    return myName;
}

void CppObject::setYear(int year)
{
    qDebug()<<"cpp setYear"<<year;
    if(year!=myYear){
        qDebug()<<"cpp emit yearChanged";
        myYear=year;
        emit yearChanged(myYear);
    }
}

int CppObject::getYear() const
{
    qDebug()<<"cpp getYear";
    return myYear;
}

void CppObject::cppSlotA()
{
    qDebug()<<"cpp slot a";
}

void CppObject::cppSlotB(const QString &str, int value)
{
    qDebug()<<"cpp slot b"<<str<<value;
}
