#include <QCoreApplication>
#include<QFile>
#include<QDataStream>
#include<QBuffer>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile fileFro("D:/Help.rar");
    QFile fileTo("D:/Media/common.rar");
    if(!fileFro.open(QIODevice::ReadOnly))
        return 0;
    if(!fileTo.open(QIODevice::WriteOnly))
        return 0;
    QDataStream out(&fileTo);
    QByteArray barry1= fileFro.readAll();
    out.setVersion(QDataStream::Qt_4_8);
    out<<barry1;
    fileFro.close();
    fileTo.close();

  QFile::remove("D:/Media/common.rar");
    return a.exec();
}
