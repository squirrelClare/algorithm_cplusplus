#include <QCoreApplication>
#include"function.h"
#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Function *fu=new Function();
    QList<double> list=fu->ReturnAns();
    qDebug()<<list;
    return a.exec();
}
