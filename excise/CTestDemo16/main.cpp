#include <QCoreApplication>
#include<QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
      enum valueClor{red,green,yellow,black};
      if(   valueClor(3)==yellow)
          qDebug()<<"Yes";
      else
          qDebug()<<"No";
    return a.exec();
}
