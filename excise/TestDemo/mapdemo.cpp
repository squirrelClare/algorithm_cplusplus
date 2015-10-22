#include "mapdemo.h"

MapDemo::MapDemo()
{

}
void MapDemo::add(QString key,int value)
{
    map.insert(key,value);
}

void MapDemo::show()
{
    qDebug()<<this->map;
}

void MapDemo::showmap()
{
    QMap<QString,int>::const_iterator i;
    for(i=map.constBegin();i!=map.constEnd();i++)
        qDebug()<<i.key()<<":"<<i.value();
}
