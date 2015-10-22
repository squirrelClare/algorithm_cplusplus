#include <QCoreApplication>
#include<datawriteread.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DataWriteRead *dwr=new DataWriteRead("C:\\Users\\lenovo\\Desktop\\in.txt");
    dwr->DataWrite("678dawgrhrhr");
    dwr->DataWrite("678dawgrhrhr");
    dwr->DataWrite("678dawgrhrhr");
    dwr->DataWrite("678dawgrhrhr");
    dwr->DataWrite("jgj678dawgrhrhr");
    dwr->DataRead();
    return a.exec();
}
