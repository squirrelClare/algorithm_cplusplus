#ifndef PERSON_H
#define PERSON_H
#include<QString>


class Person
{
public:
    Person();//构造函数
    Person(QString name,int age,QString address);//构造函数


    void Function();
    void SetName(QString name );
    void SetAge(int age);
    void SetAddress(QString address);
    static QString flag;

    static void Function1();

    //构造函数无返回值类型
    //上述两个函数的形参不一样,但是方法函数的名称是一样的,下一个函数成为上一个的重载
private:
    QString name;//人物姓名
    int age; //年龄
    QString address;//住址


    void Speak();
    void Work();
    void Eat();
    void Move();
};

#endif // PERSON_H
