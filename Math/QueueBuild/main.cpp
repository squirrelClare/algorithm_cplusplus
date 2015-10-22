#include <QCoreApplication>
#include"queue.h"
#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int p[5]={212,24,231,435,45};

    Queue qu(p,5,0,4);
    qu.Show();

    qDebug()<<qu.DeQueue();

    qu.EnQueue(45);
    qu.EnQueue(45);
    qu.EnQueue(45);

    qu.Show();

    return a.exec();
}
