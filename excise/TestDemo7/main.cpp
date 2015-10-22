#include <QCoreApplication>
#include<QList>
#include<QString>
#include<QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<QString>list;
    list<<"A"<<"B"<<"C"<<"D"<<"E"<<"F"<<"G";
    QList<QString>::iterator i;
    qDebug()<<"The forward is:";
    for(i=list.begin();i!=list.end();i++)
        qDebug()<<*i;
    qDebug()<<"**********************************************************";
    for(i=list.begin();i!=list.end();++i)
        qDebug()<<*i;
    qDebug()<<"**********************************************************";
    for(i=list.begin();i!=list.end();++i)
    {
        *i=(*i).toLower();
        qDebug()<<*i;
    }
     qDebug()<<"**********************************************************";
    qDebug()<<list;
    qDebug()<<"The backward is:";
    while(i!=list.begin())
    {
            qDebug()<<*(--i);
    }
    qDebug()<<*i;
    QList<QString>::const_iterator j=list.begin();
    while(j!=list.end())
    {
            qDebug()<<*(j++);
    }
    return a.exec();
}
