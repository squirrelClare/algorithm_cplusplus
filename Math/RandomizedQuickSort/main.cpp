#include <QCoreApplication>
#include<QDebug>
#include"sort.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int>list;
    list<<78366<<42<<242<<-199<<4234<<35345
       <<234<<325357<<324<<124<<5646<<234;
    qDebug()<<list;
    Sort *sort=new Sort();
    sort->Random(list);
    sort->Quicksort(list,0,list.length()-1);
    qDebug()<<list;
    return a.exec();
}
