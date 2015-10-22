#include<QApplication>
#include"hellodialog.h"
int main(int argc,char *argv[])
{
    QApplication a;
    HellowDialog w;
    w.show();
    a.exec();

}
