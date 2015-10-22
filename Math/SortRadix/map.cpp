#include "map.h"
#include<QMap>
#include<QDebug>

/**
基数排序法
思路:如平常的不同在于不是从最高位开始排序
二十从最后一为开始往前排序*/


Map::Map(QList<QString> list)
{//初始化类
    this->list=list;
    value_length=list.at(0).length()-1;//输入的单个数据位数
    list_length=list.length();//输入的数据个数
}

void Map::Show()
{//输出排序后的数据
    Sort();
    qDebug()<<list;
}

void Map::Sort()
{
    if(value_length<0)return;//分治法终止条件
    /*
     *新建一个QMap类,用来存储每一个数据
     *及其要比较数位上的数据*/
    QMap<QString,QChar> *map=new QMap<QString,QChar>();

    //存储过程
    for(int i=0;i<list.length();i++){
        map->insert(list.at(i),list.at(i).at(value_length));
    }
    //将value_length移动到下一个数位
    value_length--;
    //保存当前排序好的数据
    this->list=map->keys();
    //进行下一次排序
    Sort();
}
