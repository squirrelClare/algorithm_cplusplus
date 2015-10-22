#include <QCoreApplication>
#include<QDebug>
#include<QFileInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFileInfo info("‪D:/Program Files/Java/jre7/README.txt");
    qDebug()<<info.path();
    qDebug()<< info.absoluteFilePath();
    return a.exec();
}
