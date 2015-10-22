#include "SetDemo.h"

void SetDemo::demo1()
{
    QSet<QString> set;
    set<<"zhangsan1"<<"lisi2"<<"wangwu"<<"zhaoliu";
    qDebug()<<"before sort:";
    qDebug()<<"before sort:"<<set;
    qDebug()<<"******************************************************************";

}

void SetDemo::demo2()
{
}


SetDemo::SetDemo()
{
}
