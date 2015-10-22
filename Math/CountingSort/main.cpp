#include <QCoreApplication>
#include<QDebug>
#include"sort.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int>list;
    list<<2<<5<<3<<0<<2<<3<<0<<3;
    qDebug()<<list;
    Sort *sort=new Sort(list,5);
    QList<int> ans=sort->ReturnAns();
    qDebug()<<ans;
    return a.exec();
}
