//file CppObject.h
#ifndef CPPOBJECT_H
#define CPPOBJECT_H

#include <QObject>

 // Получено из QObject
class CppObject : public QObject
{
    Q_OBJECT
         // Зарегистрируем атрибут, чтобы к нему можно было получить доступ в QML - обратитесь к другим материалам для уточнения синтаксиса
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(int year READ getYear WRITE setYear NOTIFY yearChanged)

public:
    explicit CppObject(QObject *parent = nullptr);
         // Открытые функции, отмеченные макросом Q_INVOKABLE, могут быть доступны в QML
         Q_INVOKABLE void sendSignal (); // Функция - отправить сигнал

         // Добавляем метод доступа к атрибуту класса - myName
    void setName(const QString &name);
    QString getName() const;
         // Добавляем метод доступа к атрибуту класса - myYear
    void setYear(int year);
    int getYear() const;

signals:
         // Сигнал доступен в QML
         void cppSignalA (); // Сигнал без параметров
         void cppSignalB (const QString & str, int value); // сигнал с параметрами
    void yearChanged(int year);

public slots:
         // функция публичного слота доступна в QML
         void cppSlotA (); // Слот-функция без параметров
         void cppSlotB (const QString & str, int value); // Функция слота с параметрами

private:
         // Атрибуты класса
    QString myName;
    int myYear;
};

#endif // CPPOBJECT_H
