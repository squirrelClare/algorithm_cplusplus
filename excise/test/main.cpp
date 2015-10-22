#include <QCoreApplication>
#include<Demo.h>
#include<SetDemo.h>
#include<qlistdemo.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    SetDemo *sd=new SetDemo();
//    sd->demo1();

//    Demo *d=new Demo();
//    d->Demo3();
//    d->Demo1();
//    d->Demo2();
//Demo::Demo4();
//Demo::Demo5();
//Demo::ListIndexofDemo5();
//Demo::ListInsert();
QListDemo *qld=new QListDemo();
qDebug()<<"List:"<<endl;
qld->Add("1234");
qld->Add("13234");
qld->Add("41234");
qld->Add("213234");
qld->Add("qada234");
qld->Add("1dqwe134");
qld->Add("2wsad43234");
qld->Sort();
qld->ShowMemeber();
qld->ShowList();
qld->DeleteItem(2);
qld->ShowList();
qDebug()<<"***************";
qDebug()<<qld->GetChar(2);
    return a.exec();
}

