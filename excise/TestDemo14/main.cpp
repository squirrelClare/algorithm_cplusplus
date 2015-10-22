#include "widget.h"
#include<dialog.h>
#include <QApplication>
#include<QDialog>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    Dialog dialog_1;
    if(dialog_1.exec()==QDialog::Accepted)
    {
    w.show();
     return a.exec();
    }
    else return 0;

}
