#include <QCoreApplication>
#include<QDebug>
#include<QList>
#include"solver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int>list;
    list<<86<<9<<14<<18<<9<<91<<64<<71<<641
       <<96<<3<<123<<1731<<73<<19<<8<<3<<61<<96<<1<<91;

    qDebug()<<Solver::MaxNum(list);
    qDebug()<<Solver::MinNum(list);
    qDebug()<<Solver::MNum(list);
    return a.exec();
}
