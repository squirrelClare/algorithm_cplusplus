#include <QCoreApplication>
#include<QList>
#include<QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int>list;
    list<<78<<13<<99<<3134<<313<<545<<424<<3657;
    qDebug()<<list;
   qDebug()<< list.mid(2,4);
   int ac=1,bc=0;
   qDebug()<<(int)(ac+bc)/2;
    return a.exec();
}
