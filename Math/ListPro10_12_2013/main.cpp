#include <QCoreApplication>
#include<list.h>
#include<node.h>
//#define NULL 0
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    List *list=new List();
    list->ListInsert(12);
    list->ListInsert(23);
    list->ListInsert(56);
    list->ListInsert(76);
    list->ListInsert(94);

    list->ShowOut();
    return a.exec();
}
