#include <QCoreApplication>
#include<QTextCodec>
#include<QDebug>
#include"solver.h"
#include<QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    QList<int> lengthList,valueList;
    //钢条切割问题初始数据输入
    //    for(int i=1;i<=10;++i)
    //    lengthList<<i;
    //    valueList<<1<<5<<8<<9
    //            <<10<<17<<17
    //           <<20<<24<<30;


    lengthList<<3<<4<<7<<8<<9;
    valueList<<4<<5<<10<<11<<13;

    int totalLength=117;//钢条的长度值

    qDebug()<<"长度列表为："<<lengthList<<endl
           <<"价格列表为"<<valueList;

    if(totalLength>200){
        qDebug()<<"钢条长度过长，运行时间会加长，请重新设定钢条超度值！！";
        return a.exec();
    }
    Solver *solver=new Solver(lengthList,valueList,totalLength);
    solver->ShowResult();

    return a.exec();
}
