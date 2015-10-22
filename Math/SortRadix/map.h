#ifndef MAP_H
#define MAP_H
#include<QString>
#include<QMap>

class Map
{
public:
    Map(QList<QString> list);
    void Show();
private:
    QList<QString>list;
    void Sort();
    int list_length,value_length;
};

#endif // MAP_H
