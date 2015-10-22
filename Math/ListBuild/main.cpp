#include <QCoreApplication>
#include"list.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    List list;
    list.AddAtEnd(78);
    list.AddAtEnd(34);
    list.AddAtEnd(43);
    list.AddBefore(0,31);
    list.AddBefore(3,190);
    list.ShowAll();
    return a.exec();
}
