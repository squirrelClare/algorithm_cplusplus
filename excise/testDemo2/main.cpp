#include <QCoreApplication>
#include<qlisttestdemo.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QListTestDemo::Testprepend();
    qDebug()<<"***********************************************";
    QListTestDemo::Testpush_back();
      qDebug()<<"***********************************************";
    QListTestDemo::Testpush_front();
      qDebug()<<"***********************************************";
    QListTestDemo::TesttoSet();
      qDebug()<<"***********************************************";
    QListTestDemo::Testremoveall();
      qDebug()<<"***********************************************";
      QListTestDemo::Testvalue();
      qDebug()<<"***********************************************";
      QListTestDemo::Testopertor1();
          qDebug()<<"***********************************************";
      QListTestDemo::Testopertor2();
    return a.exec();
}
