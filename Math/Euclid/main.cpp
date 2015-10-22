#include <QCoreApplication>
#include<QDebug>
#include<teuclid.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    TEuclid *t=new TEuclid();
    long num_a=131;
    long num_b=3141517;
    long gcd=t->Gcd(num_a,num_b);
    qDebug()<<"a="<<num_a<<endl;
    qDebug()<<"b="<<num_b<<endl;
    qDebug()<<"gcd(a,b)="<<gcd<<endl;
    return a.exec();
}
