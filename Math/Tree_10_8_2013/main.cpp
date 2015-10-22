#include <QCoreApplication>
#include<QDebug>

#include"tree.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Tree tr;
    qDebug()<<tr.IsEmpty();
    tr.Append(15);
    tr.Append(6);
    tr.Append(18);
    tr.Append(3);
    tr.Append(7);
    tr.Append(17);
    tr.Append(20);
    tr.Append(2);
    tr.Append(4);
    tr.Append(13);
    tr.Append(9);

    qDebug()<<tr.MaxFromRoot()->GetKey();
    qDebug()<<tr.MinFromRoot()->GetKey();
    qDebug()<<tr.Predecessor(tr.MaxFromRoot())->GetKey();
    qDebug()<<tr.Successor(tr.MinFromRoot())->GetKey();
    tr.Show();
    qDebug()<<tr.Predecessor(tr.SearchFromRoot(18))->GetKey();
    return a.exec();
}
