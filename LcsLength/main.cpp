#include <QCoreApplication>
#include<QVector>
#include"solver.h"
#include<QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Solver* s=new Solver();
    QVector<int> X,Y;
    X<<1<<2<<3<<2<<4<<1<<2;
    Y<<2<<4<<3<<1<<2<<1;
    s->LcsLength(X,Y);
    s->PrintLcs();
    delete s;
    s=__null;
    return a.exec();
}
