#include <QCoreApplication>
#include<QDebug>
#include"function.h"
int main(int arg,char *argv[])
{
    QCoreApplication a(arg,argv);
    Function *fun=new Function();

   QString str= fun->ExtractWebFileName("dadqeq/dadadsas/deqeqweq");
    qDebug()<<str;
    QString s="dhaduieyiqueyqiuey509";
    qDebug()<<s.right(8);
            return a.exec();

}
