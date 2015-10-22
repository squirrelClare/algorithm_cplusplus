#include <QCoreApplication>
#include<QDataStream>
#include<QFile>
#include<QDebug>
#include<QString>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile file("D:/Program Files/QT/TestQDataStreamDemo1/output.txt");
    file.open(QIODevice::Append|QIODevice::Text);
//    qDebug()<< file.isOpen();
    QDataStream out(&file);
    out<<QString("This is a QString!")<<(qint32)42;
    file.close();

    QFile data("D:/Program Files/QT/TestQDataStreamDemo1/output.txt");
    data.open(QIODevice::ReadOnly|QIODevice::Text);
    QString str;int intA;
    QDataStream in(&data);
    in>>str>>intA;
qDebug()<<str<<endl<<intA;
    data.close();
    return a.exec();

}
