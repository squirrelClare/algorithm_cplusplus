#include <QCoreApplication>
#include"sort.h"
#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //输入待处理的数组
    QList<int>list;
    list<<13<<314<<23<<32<<43424<<4536<<3253<<6547<<34<<78697<<2535<<32<<231;
    //在控制台输出数组
    qDebug()<<list;
    //实例化排序类Sort
    Sort *sort=new Sort(list);
    //开始排序
    sort->ListSort();
    //返回排序后的数组
    QList<int>result=sort->GetResult();
    //在控制台输出数组
    qDebug()<<result;
    return a.exec();
}
