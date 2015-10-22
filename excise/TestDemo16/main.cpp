#include <QCoreApplication>
#include<QDataStream>
#include<QByteArray>
#include<QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    static char bindata[] = { 56, 1, 44, 78,73,24,27 };
       QByteArray array;
       array.setRawData( bindata, sizeof(bindata) );   // a指向bindata
       QDataStream s(& array, QIODevice::ReadOnly);            // 打开a的数据

       char data1,data2,data3,data4,data5,data6,data7;
      s >>data1>>data2>>data3>>data4>>data5>>data6>>data7;                        // 读取原始的bindata
       //array.( bindata, sizeof(bindata) ); // 完成
      qDebug()<<data1<<data2<<data3<<data4<<data5<<data6<<data7;

    return a.exec();
}
