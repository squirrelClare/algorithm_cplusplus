
#include "demo.h"
#include<QDebug>
Demo::Demo(QString name,int age,QString addr)
{
    this->name=name;
    this->addr=addr;
    this->age=age;
}

Demo::~Demo()
{
}


void Demo::Show()
{
    qDebug()<<this->name<<this->age<<this->addr;
}
int Demo::max=4;
