#include <QCoreApplication>
#include<QDebug>
#include<QList>
#include"maxheap.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int>list;
    list<<13<<314<<23<<32<<43424<<4536<<3253<<6547<<34<<78697<<2535<<32<<231;
    MaxHeap *heap=new MaxHeap(list);
    heap->Show();
    heap->BuildMaxHeap();
    heap->Show();
    QList<int> result=heap->GetList();
    qDebug()<<"The result is:"<<result;
    return a.exec();
}
