#include <QCoreApplication>
#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //    int A[]={11,23,13,24,56,34};
    //    int *p;
    //    p=A;
    //    qDebug()<<p<<"***"<<A;
    //    qDebug()<<A[3]<<"***"<<p[3];
    //    qDebug()<<*p<<"***"<<*A;
    //    qDebug()<<*(p+2)<<"***"<<A[2];
    int value=3;
    int *p=&value;
    qDebug()<<p<<endl<<*p<<endl<<&value<<endl<<&p;
    return a.exec();
}
