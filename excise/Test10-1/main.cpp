#include <QCoreApplication>
#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int b_1[100];
    int *p;
    b_1[0]=2;
    b_1[3]=4;
    p=b_1;
    for(int i=0;i<4;++i)
        qDebug()<<p[i];

    qDebug()<<"**************************";
    int arry[100];
    for(int i=0;i<100;++i)
        arry[i]=i*i;
    p=arry;

    for(int i=0;i<100;++i)
        qDebug()<<p[i];

//    int *b_2=(int *) malloc(sizeof(int) * 100);
//    b_2[0]=19;
//    qDebug()<<b_2[0];


    return a.exec();
}
