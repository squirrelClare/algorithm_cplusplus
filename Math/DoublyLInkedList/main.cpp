#include <QCoreApplication>
#include"list.h"
#include<QDebug>
#include<QtCore/qmath.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    List list;
    list.Append(78);
    list.Append(645);
    list.Append(31);
    list.Append(543);
    list.Append(652);
    list.Append(236);
    list.Append(854);
    list.Append(423);
    list.Show();
    qDebug()<<list.IndexOf(423);
    qDebug()<< list.Delete(2);
    list.Show();
    return a.exec();
}
