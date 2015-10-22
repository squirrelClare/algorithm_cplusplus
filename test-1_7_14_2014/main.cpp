#include <QCoreApplication>
#include"productor.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Productor p(QString("dsd"),QString("ewq"),QString("hyyy"),QString("nvbnv"));
    Productor p2;
    return a.exec();
}
