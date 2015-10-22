#include <QCoreApplication>
#include"sort.h"
#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int *A=new int[10];
    A[0]=2;
    A[1]=0;
    A[2]=4;
    A[3]=2;
    A[4]=8;
    A[5]=7;
    A[6]=2;
    A[7]=4;
//   int B[]={423,2131,342,132535,12};
//   qDebug()<<sizeof(A);
    Sort *sort=new Sort(A,8);
    sort->Show();
    return a.exec();
}
