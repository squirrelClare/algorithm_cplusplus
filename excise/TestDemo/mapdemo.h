#ifndef MAPDEMO_H
#define MAPDEMO_H
#include<QMap>
#include<QString>
#include<QDebug>
class MapDemo
{
private:
     QMap<QString,int> map;
public:
    MapDemo();
    void add(QString key, int value);
    void show();
    void showmap();
};

#endif // MAPDEMO_H
