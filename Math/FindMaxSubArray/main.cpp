#include <QCoreApplication>
#include<maxarray.h>
#include<QDebug>
#include<QList>
#include<QTextCodec>
#include<QTextStream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    MaxArray *mArray=new MaxArray();
    QList<double>list;
    list<<13<<-3<<-25<<20<<-3<<-16<<-23<<18<<20<<-7<<12<<-5<<-22<<15<<-4<<7;
    qDebug()<<QObject::tr("股市走势为:")<<endl<<list;
    mArray->MaxArrayReturn(list).Show();

    QList<double>list1=mArray->InputData("C:/Users/lenovo/Desktop/data.txt");
    mArray->MaxArrayReturn(list1).Show();
    return a.exec();
}
