#include <QCoreApplication>
#include<QTextCodec>
#include"person.h"
#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

//    Person *p=new Person("John",67,"somewhere");
//    p->Function();

//    Person *p1=new Person();
//    p1->SetName("John");
//    p1->SetAge(90);
//    p1->SetAddress("fwdge");
//    p1->Function();


      qDebug()<<Person::flag;
    return a.exec();
}
