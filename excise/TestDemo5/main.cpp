#include <QCoreApplication>
#include<QDebug>
#include<QString>
#include<QStringList>
#include<QDataStream>
#include<QVariant>
#include<QByteArray>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    bool ok=false;
//    double d=0;
//   qDebug()<<ok<<d;
//    d=QString("1234.56e-02").toDouble(&ok);
//    qDebug()<<ok<<d;
//    QString str="dafwefqeq";
// const   char  *ch;
// ch=str.toAscii();
//  ;
//    for(int i;i<5;i++)
//        qDebug()<<*ch;

//    QByteArray qa;
//    QStringList sl;
//    sl.append("lgkhkqhwkjqjbdq");
//    sl.at(0).toWCharArray(qa);
//    qDebug()<< qa;
//    QString str="0002141";
////    QString str_1=QString("132").arg("dad","daq","qfe","a134");
//qDebug()<<str.toInt();
//double db=12314123;
//qDebug()<<QString::number(db);
    QString str="I am a HuiWen student!";
    qDebug()<<str.mid(2);
    qDebug()<<str.left(3);
    qDebug()<<str.left(5);
    qDebug()<<str.left(8);
    qDebug()<<str.right(6);
    qDebug()<<str.right(5);
    qDebug()<<str.right(4);
    qDebug()<<str.right(3);
    qDebug()<<str.count();
    qDebug()<<str.count('u');
    QByteArray qa=str.toAscii();
    const char* ch= qa.data();
    for(int i=0;i<qa.length();i++)
    qDebug()<< ch[i];
    return a.exec();
}


