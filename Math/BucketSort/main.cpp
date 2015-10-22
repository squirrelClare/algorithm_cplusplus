#include <QCoreApplication>
#include<QDebug>
#include<QTextCodec>
#include<QList>
#include"solver.h"
void InsertSort(QList<int> & list);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    QList<int>list;
    list<<12<<32<<45<<32<<35<<13<<35<<65<<65<<67<<56<<73<<56<<
          42<<65<<21<<17<<51<<43<<67<<31;
    Solver *solver=new Solver(list,10,11);
    solver->Show();
    return a.exec();
}
