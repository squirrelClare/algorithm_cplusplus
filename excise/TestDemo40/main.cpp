#include <QCoreApplication>
#include<QDebug>
#include"demo.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Demo de("zhangsan",13,"china");
    de.Show();
    return a.exec();
}
