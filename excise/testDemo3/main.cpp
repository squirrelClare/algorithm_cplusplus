#include <QCoreApplication>
#include<testqdatasream.h>
#include<QTextCodec>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
     QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
     QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));
    TestQDataSream::testOut();
    TestQDataSream::testIn();
    TestQDataSream::others();
    return a.exec();
}
