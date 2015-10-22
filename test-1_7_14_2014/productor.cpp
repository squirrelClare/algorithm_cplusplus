#include "productor.h"


Productor::Productor()
{

}


Productor3::Productor3()
{
    qDebug()<<QString("default\t")+"Product3";
}


Productor2::Productor2()
{
    qDebug()<<QString("default\t")+"Product2";
}


Productor1::Productor1()
{
    qDebug()<<QString("default\t")+"Product1";
}


Productor::Productor(QString str1, QString str2, QString str3, QString str4):
    p1(str1),p2(str2),p3(str3),Productor1(str3),Productor2(str2),Productor3(str1)
{
        qDebug()<<"Productor "+str4;
}
