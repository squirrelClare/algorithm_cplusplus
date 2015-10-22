#include <QCoreApplication>
#include<QTextStream>
#include<QFile>
#include<QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile data("D:/Program Files/QT/TestQtextStreamDemo1/output.txt");
    data.open(QIODevice::Append|QIODevice::Text);
    qDebug()<< data.isOpen();
    QTextStream out(&data);
    out<<endl<<"Result:"<<qSetFieldWidth(10)<<left<<3.14<<left<<2.77<<left<<"dawe"<<left<<1141;
    data.close();
    return a.exec();
}
