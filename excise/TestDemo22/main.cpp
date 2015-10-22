#include <QCoreApplication>
#include<QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString str=QString("‪C:/Users/lenovo/Desktop/HttpDownload");
    qDebug()<<str<<endl;
    qDebug()<<str.replace('/',"\\").replace('\\','/');
    return a.exec();
   // qDebug()<<QString("‪C:\Users\lenovo\Desktop\HttpDownload");
}
