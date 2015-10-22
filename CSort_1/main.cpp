#include <QCoreApplication>
#include<QDebug>
#include"sort.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int arr[10]={12,34,23,43,44,32,22,45,65,90};
    sort *arry=new sort(arr,10);
    sort *arry_1=new sort(arr,10);
    sort *arry_2=new sort(arr,10);
    arry->ShowOut();
    qDebug()<<".......................................";
    //arry_1->InsertSort();
    //arry_1->ShowOut();
    qDebug()<<".......................................";
   // arry->BubbleSort();
    //arry->ShowOut();
    qDebug()<<".......................................";
    arry->RadixSort();
    arry->ShowOut();
    qDebug()<<".......................................";


    
    return a.exec();
}
