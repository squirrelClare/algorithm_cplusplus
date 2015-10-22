#include <QCoreApplication>
#include<QString>
#include<QList>
#include<QDebug>
#include<QListIterator>
#include<QMutableListIterator>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<QString> list;
    list<<"zhangsan_1"<<"zhangshan_2"<<"zhangsan_3"<<"zhansan_5"<<"zhangsan_4";
    QListIterator<QString> i(list);
    while(i.hasNext())
        qDebug()<<i.next();
    while(i.hasPrevious())
        qDebug()<<i.previous();
    qDebug()<<"****************************************************";
    qDebug()<<list;
    QMutableListIterator<QString>j(list);
    j.toBack();
    while(j.hasPrevious())
    {
        QString str=j.previous();
        if(str=="zhangshan_2")
            j.remove();
    }
    j.insert("Q");
    j.toBack();
    if(j.hasPrevious())
        j.previous()="N";
    j.previous();
    j.setValue("M");
    j.toFront();
    qDebug()<<"This list is:";
    while(j.hasNext())
        qDebug()<<j.next();
    qDebug()<<list;

    return a.exec();
}
