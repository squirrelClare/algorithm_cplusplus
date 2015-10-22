#include <QCoreApplication>
#include<QList>
#include"someclass.h"
#include<QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    QList<int>** list;
//    list=new QList<int>*[10];
//    for(int i=0;i<10;++i){
//        list[i]=new QList<int>();
//    }
//    list[2]->append(23);
//    list[2]->append(232);

//    list[2]->at(1);

    SomeClass s("hellow",2013);//直接调用有参数的构造函数
    qDebug()<<s.GetString()<<endl<<s.GetValue()<<endl;

    SomeClass s_1(s);//调用复制构造函数
    qDebug()<<s_1.GetString()<<endl<<s_1.GetValue()<<endl;

    s_1.SetString("nihao").SetValue(20123);
    qDebug()<<s_1.GetString()<<endl<<s_1.GetValue()<<endl;

    SomeClass s_2;
    s_2=s;//调用类的赋值操作"="
    qDebug()<<s_2.GetString()<<endl<<s_2.GetValue()<<endl;

    s_1+=s;//调用运算符"+="

    qDebug()<<s_1.GetString()<<endl<<s_1.GetValue()<<endl;

    return a.exec();
}
