#ifndef PRODUCTOR_H
#define PRODUCTOR_H
#include<QString>
#include<QDebug>
class Productor1
{
public:
    Productor1();
    Productor1(QString str)
    {
        qDebug()<<"Productor1  "+str;
    };
};

class Productor2
{
public:
    Productor2();
    Productor2(QString str)
    {
        qDebug()<<"Productor2  "+str;
    };
};

class Productor3
{
public:
   Productor3();
    Productor3(QString str)
    {
        qDebug()<<"Productor3  "+str;
    };
};
class Productor:public Productor1,public Productor2,public Productor3
{
public:
    Productor();
    Productor(QString str1,QString  str2,QString str3,QString str4);
private:
    Productor1 p1;
    Productor2 p2;
    Productor3 p3;
};


#endif // PRODUCTOR_H
