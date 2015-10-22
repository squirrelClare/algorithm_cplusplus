#include <QCoreApplication>
#include"map.h"
#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<QString>list;
    list<<"3214"<<"2431"<<"4289"
       <<"3424"<<"9799"<<"0013"<<"0212";
    qDebug()<<list;
    Map *map=new Map(list);
    map->Show();
    delete map;
    return a.exec();
}
