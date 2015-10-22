#include <QCoreApplication>
#include<QDir>
#include<QDebug>
#include<QList>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString str="D:/Warcraft3_1.24E/Replay/11Game";
    QDir path=QDir(str);
    qDebug()<< path.isAbsolute();
    qDebug()<<path.isRelative();
    qDebug()<<path.isAbsolutePath("/Replay/11Game");
    qDebug()<<path.isRelativePath("/Replay/11Game");
    qDebug()<<path.path();
    qDebug()<<path.count();
    return a.exec();
}
