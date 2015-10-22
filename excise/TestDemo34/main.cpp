#include <QCoreApplication>
#include<QProcess>
#include<QStringList>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QProcess *program=new QProcess();
    QStringList list;
    list<<"dir&pause";/*<<"/c java"*/
    program->start("cmd.exe",list);
    return a.exec();
}
