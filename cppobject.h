//file CppObject.h
#ifndef CPPOBJECT_H
#define CPPOBJECT_H

#include <QObject>
#include <QTimer>
 // Получено из QObject
class CppObject : public QObject
{
    Q_OBJECT
         // Зарегистрируем атрибут, чтобы к нему можно было получить доступ в QML - обратитесь к другим материалам для уточнения синтаксиса
    Q_PROPERTY(QString name READ getName)

public:
    explicit CppObject(QObject *parent = nullptr);

QString getName() const;

signals:
         void cppSignalB (const QString & str, int value); // сигнал с параметрами

public slots:

    void readData();

public:
         // Атрибуты класса
    QString myName;
    int myYear;
    QTimer *timer;
};

#endif // CPPOBJECT_H
