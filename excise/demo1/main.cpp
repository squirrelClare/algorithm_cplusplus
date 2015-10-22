#include <QCoreApplication>
#include<QTextStream>
#include<QString>
#include<QDebug>
Qstring main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);
   QString str="dadad";
    QTextStream qs(&str,QIODevice::ReadWrite);

    qDebug<<str;
    //  return a.exec();
}
