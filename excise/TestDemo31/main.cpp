#include <QCoreApplication>
#include<QtAlgorithms>
#include<QDebug>
#include<QVector>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    enum typ{  ATTACH_ADV=1,
     ATTACH_PAY =2,
     ATTACH_YOUHUI=3 ,
     ATTACH_SHUIPAI =4,
     ATTACH_ARTICAL=5,
     ATTACH_GAME=6,
     ATTACH_QUERY=7};

for(int i=ATTACH_ADV;i!=ATTACH_QUERY+1;i++)
    qDebug()<<i;
a.exec();
}
