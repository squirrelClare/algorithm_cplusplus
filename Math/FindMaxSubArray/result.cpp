#include "result.h"
#include<QDebug>
Result::Result()
{
this->highAns=0;
 this->lowAns=0;
    this->sumAns=0;

}

Result::~Result()
{
}

void Result::Show()
{qDebug()<<QObject::tr("要想获得最大利润:");
    qDebug()<<QObject::tr("在第")<<this->lowAns<<QObject::tr("天结束时买入")<<endl
           <<QObject::tr("在第")<<this->highAns+1<<QObject::tr("天结束时卖出")<<endl<<
             QObject::tr("最大利润为每股")<<this->sumAns<<QObject::tr("元")<<endl;
}
