#include "setdemo.h"
#include<QDebug>
#include<QSet>
#include<QString>
SetDemo::SetDemo()
{
}

void SetDemo::Demo1()
{//用for和Iterator输出.
    QSet<QString> set;
    set<<"zhangshan"<<"lisi"<<"wangwu"<<"nihao";
    qDebug()<<"The set is:"<<set;
    qDebug()<<"Print the set with 'for' and 'Iterator':";
    QSet<QString>::Iterator it;

    for(it=set.begin();it!=set.end();it++)
        qDebug()<<*it;
    qDebug()<<"***************************************************************";
}

void SetDemo::Demo2()
{
    //用while进行输出.
    QSet<QString> set;
    set<<"zhangshan"<<"lisi"<<"wangwu"<<"nihao";
    qDebug()<<"The set is:";
    qDebug()<<set;
    qDebug()<<"Print the set with 'while' and 'Iterator':";
    QSet<QString>::Iterator i=set.begin();
    while(i!=set.end())//比较器不能比较大小.
    {
        qDebug()<<(*i).toUpper();
        i++;
    }
    qDebug()<<"***************************************************************";
}

void SetDemo::Demo3()
{
    QSet<QString> set;
    set<<"zhangshan"<<"lisi"<<"wangwu"<<"nihao";
    qDebug()<<"The set is:";
    qDebug()<<set;
    QSet<QString>::const_iterator i;
     qDebug()<<"Print the set with 'for' and 'const_iterator':";
    for (i = set.constBegin(); i != set.constEnd(); ++i)
        qDebug() << *i;
    qDebug()<<"***************************************************************";
}
