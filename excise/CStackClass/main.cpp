 #include <QCoreApplication>
#include<QDebug>
#include<iostream>
#include"rectangle.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Rectangle *p=new Rectangle();
    p->Function();



    
    return a.exec();
}
