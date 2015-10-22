#include "solver.h"
#include<QDebug>
/**
    与SteelBarCut中的不同之处在于，
    该算法将每次局部最优解存储起来，
    以便再次需要求解该局部最优解的
    时候直接从记录中调取。以牺牲内存
    为代价获得运行时间上的提升*/
Solver::Solver()
{
}

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
              .arg(totalLength).arg(MemoizedCutRod(totalLength));
}

int Solver::MemoizedCutRod(const int totalLength)
{
    //初始化record数组，用以记录局部最优解
    for(int i=0;i<=totalLength;++i)
        record<<-1000;
    return MemoizedCutRodAux(totalLength);
}

int Solver::MemoizedCutRodAux(const int totalLength)
{
    //求解过程，和SteelBarCut中的一样
    if(record.at(totalLength)>=0)return record.at(totalLength);

    int currentBest=-10;

    if(totalLength<=0)
        currentBest=0;
    else{
        for(int i=0;i<barList->size();++i){
            if((barList->value(i).barLength)<=totalLength){
            currentBest=qMax(currentBest,barList->value(i).barValue+
                            MemoizedCutRodAux(totalLength-barList->value(i).barLength));
            }
        }
    }

    record.replace(totalLength,currentBest);
    return currentBest;
}


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
