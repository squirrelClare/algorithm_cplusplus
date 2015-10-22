#include "barpart.h"

//将价格表的样例封装成一个类
BarPart::BarPart()
{
}

BarPart::BarPart(const int barLength,const int barValue)
{
    //barValue为对应barValue的价格
    this->barLength=barLength;
    this->barValue=barValue;
}
