#include <QCoreApplication>
#include<QDebug>
#include<QList>
#include"sortfuction.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int>list;
    list<<7<<84<<49<<61<<76<<36<<17;
    qDebug()<<list;
    SortFuction *sort=new SortFuction(list);
    sort->MergeSort(0,list.length()-1);
    sort->Show();
    return a.exec();
}
