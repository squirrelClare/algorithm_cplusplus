#include <QCoreApplication>
#include<QDebug>
QList<int> &Dolphin(QList<int> &list);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int>list;
    list<<798<<478<<19<<71<<89<<38<<916<<31
       <<78<<63<<78<<13<<51<<83<<51<<28<<35<<1;
    qDebug()<<list;
    Dolphin(list);
    qDebug()<<list;
    return a.exec();
}


QList<int> &Dolphin(QList<int> &list){
    QList<int>trans=list.mid(list.length()-4,-1);
    for(int i=list.length()-1;i>3;i--)
        list.replace(i,list.at(i-4));
    for(int i=0;i<4;i++)
        list.replace(i,trans.at(i));
    return list;
}
