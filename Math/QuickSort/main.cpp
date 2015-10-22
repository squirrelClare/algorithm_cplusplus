#include <QCoreApplication>
#include<QList>
#include"sort.h"
#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> list;
    list<<678<<32<<89<<87<<876<<656<<676<<6<<55<<44<<-14141<<43<<435<<3453<<234<<435<<324<<13;
    qDebug()<<list;
    Sort *sort=new Sort();
    sort->Quicksort(list,0,list.length()-1);
    qDebug()<<list;
    return a.exec();
}
