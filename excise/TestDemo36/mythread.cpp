#include "mythread.h"
#include<QDebug>
#include<QFile>

MyThread::MyThread(QObject *parent) :
    QThread(parent)
{
    stopped=false;
}

void MyThread::Stop()
{
    stopped=true;
}

void MyThread::run()
{
    qreal i=0;
    QFile file("data.txt");
    if(!file.open(QFile::WriteOnly)){
        qDebug()<<"Failed open";
        return;
    }
    QTextStream out(&file);
    while (!stopped) {
//        qDebug()<<QString("In MyThread %1").arg(i++);
        QString str=QString("In MyThread %1").arg(i++);
        out<<str<<'\n';
       out.flush();
        stopped=false;
    }
}
