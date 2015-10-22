#include <QCoreApplication>
#include<QTextCodec>
#include<setdemo.h>
#include<mapdemo.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextCodec *qtc=QTextCodec::codecForName("gb2312");
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("gb2312"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));

    SetDemo::Demo1();
    SetDemo::Demo2();
    SetDemo::Demo3();


    MapDemo *m=new MapDemo();
    m->add("jon",11);
    m->add("sim",14);
    m->add("jim",12);
    m->add("lucy",14);
    m->add("kim",15);
    m->add("jack",31);
    m->add("green",21);
    m->show();
    m->showmap();
    return a.exec();
}
