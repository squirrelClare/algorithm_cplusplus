#include <QCoreApplication>
#include"tree.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Tree *tr=new Tree();
    tr->Append(463);
    tr->Show();

    tr->Append(231);
    tr->Show();

    tr->Append(34);
    tr->Show();

    tr->Append(13);
    tr->Show();

    tr->Append(38);
    tr->Show();

    tr->Append(564);
    tr->Show();

    tr->Append(898);
    tr->Show();

    tr->Append(76);
    tr->Show();

    return a.exec();
}
