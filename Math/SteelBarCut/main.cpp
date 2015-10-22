#include <QCoreApplication>
#include"solver.h"
#include<QList>
#include<QDebug>
#include<QTextCodec>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    //    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    //    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    QList<int> lengthList({1,2,3,4,5,6,7,8,9,10}),
            valueList({1,5,8,9,10,17,17,20,24,30});
    //钢条切割问题初始数据输入
    //    for(int i=1;i<=10;++i)
    //    lengthList<<i;
    //    valueList<<1<<5<<8<<9
    //            <<10<<17<<17
    //           <<20<<24<<30;
    int totalLength=23;//钢条的长度值

    qDebug()<<"length table："<<lengthList<<endl
           <<"price table:"<<valueList;

    if(totalLength>50){
        qDebug()<<"error！！";
        return a.exec();
    }
    Solver *solver=new Solver(lengthList,valueList,totalLength);
    solver->ShowResult();
    return a.exec();
}
