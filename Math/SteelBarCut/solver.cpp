#include "Solver.h"
#include<QDebug>
/**
钢条切割
该算法时间T(n)=2^n,所以钢条长度大于20时，算法性能
明显变差*/
Solver::Solver(const QList<int> lengthList, const QList<int> valueList, const int totalLength)
{  /*lengthList为可以切割的长度选项
    valueList为每个长度对应的价格
    totalLength为原始钢条长度*/

    this->totalLength=totalLength;
    barList=new QMap<int,BarPart>();

    //将价格表的样例存入一个QMap中
    for(int i=0;i<lengthList.length();++i){
        BarPart *part=new BarPart(lengthList.at(i),valueList.at(i));
        barList->insert(i,*part);
    }
}

void Solver::ShowResult()
{
    //输出最佳结果
    qDebug()<<QString("长度为%1的钢条最多可卖%2")
              .arg(totalLength).arg(CutRod(totalLength));
}

int Solver::CutRod(const int totalLength)
{
//    if(totalLength<=0)return 0;//递归终止条件(钢条切割问题)
    if(totalLength<3)return 0;//0-1规划问题
    int bestChoice=-1;//初始化局部最优解

    //求解最优结果的算法主体部分
    for(int i=0;i<barList->size();++i){
        if((barList->value(i).barLength)<=totalLength){
        bestChoice=qMax(bestChoice,barList->value(i).barValue+
                        CutRod(totalLength-barList->value(i).barLength));
        }
    }
    return bestChoice;//返回局部最优解
}

