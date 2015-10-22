#include "person.h"
#include<QDebug>

Person::Person()
{
    name="NULL";
    age=-1;
    address="sky";
}

Person::Person(QString name, int age, QString address)
{
    this->address=address;//使用this的理由在于,类的私有数据中具有和形参相同的名称,加上this便于编译器区分
    this->age=age;
    this->name=name;
    //构造函数一般只进行类的数据初始化动作,不做其他操作
}

void Person::Function()//输出人的行为功能
{
    Eat();
    Work();
    Speak();
    Move();
}

void Person::SetName(QString name)//设置人的名字
{
    this->name=name;

}

void Person::SetAge(int age)//设置人的年龄
{
    this->age=age;
}

void Person::SetAddress(QString address)//设置人的住址
{
    this->address=address;
}

void Person::Function1()
{
    qDebug()<<"Hello world!!!";
}

void Person::Speak()//说出人的名字\年龄\住址
{
    qDebug()<<"姓名"<<name<<endl<<"年龄"<<age<<endl
           <<"住址"<<address;
}

QString Person::flag="alive";
void Person::Work()//工作
{
    qDebug()<<"开始工作";
}

void Person::Eat()//吃饭
{
    qDebug()<<"吃饭";
}

void Person::Move()//行走
{
    qDebug()<<"行走";
}
