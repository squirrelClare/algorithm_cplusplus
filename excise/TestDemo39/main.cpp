#include <QCoreApplication>
#include<QDebug>
#include"linearlist.h"
void Swap(int &x,int &y);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    LinearList<double> list(5);
    list.add(12).add(123).add(2141).add(45.656).add(3.1415);
    int value_1=132,value_2=13;
    qDebug()<<value_1<<value_2;
    Swap(value_1,value_2);
    qDebug()<<value_1<<value_2;
    QString str1("Hello");
    QString &str=str1;
    qDebug()<<str;
    return a.exec();
}
void Swap(int &x,int &y){
    int trans;
    trans=x;
    x=y;
    y=trans;
}
int & f()
{
    QList *list=new QList();delete list;
    int *x =new int;
    *x = 2;
    int *p=x;
    return p;
}
