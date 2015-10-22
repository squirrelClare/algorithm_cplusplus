#include <QCoreApplication>
#include<QDebug>
#include<QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    typedef int Height,Weight;
    Height val=99;
    Weight val_1=1000;
    qDebug()<<val<<endl<<val_1;
    
    QList<double>list,list1;
    list<<637<<43<<4<<34<<56<<546<<453<<435;
    list.append(6435);
    qDebug()<<list;
    list1=list;

    qSort(list);
    qDebug()<<list;
    qDebug()<<list.length()<<" "<<list.size();
     qDebug()<<list1;
     qDebug()<<list.at(2)<<list1.indexOf(34)<<endl<<"******************************";

     qDebug()<<list1.back()<<endl<<list1<<list1.back();
     list1.replace(1,100);
     qDebug()<<list1;
     list1.swap(0,list1.size()-1);
     qDebug()<<list1;
     qDebug()<<qMax(qMax(34,65),56)<<" "<<qMin(77,87);
    return a.exec();
}
