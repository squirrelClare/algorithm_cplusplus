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
{
    /*lengthList为可以切割的长度选项
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
    RodAns ans=BottomUpCutRod(totalLength);
    qDebug()<<QString("长度为%1的钢条最多可卖%2")
              .arg(totalLength).arg(ans.bestValue);
    qDebug()<<QString("最好方案为：");

    int tlength=totalLength;
    QList<int>outPut;
    while(tlength>=3){
        outPut<<ans.proAns.at(tlength);
        tlength=tlength-ans.proAns.at(tlength);
    }
    qDebug()<<outPut;
}

RodAns Solver::BottomUpCutRod(const int totalLength)
{
    /*
    原来的算法在第二次for循环的时候会调用record中的值，但是barvalue的值
    并不是连续的，对于其中的间断点会被record的中初始值所代替，因此将record
    的值全部初始化为0（最终的局部最优化结果肯定是非负的）*/

    //record数组初始化
    QList<int>proans;
    for(int i=0;i<=totalLength;++i){
        record<<-100;
        proans<<0;
    }
    //算法主体部分
    for(int j=0;j<=totalLength;++j){
        int currentBest=0;
        for(int i=0;i<barList->size();++i){
            if(((j-barList->value(i).barLength)>=0)&&currentBest<barList->value(i).barValue+
                    record.at(j-barList->value(i).barLength)){
                currentBest=barList->value(i).barValue+
                             record.at(j-barList->value(i).barLength);
                proans.replace(j,barList->value(i).barLength);//保存局部最佳结果的第一段切割长度
            }
        }
        record.replace(j,currentBest);
    }
    RodAns ans;
    ans.bestValue=record.at(totalLength);
    ans.proAns=proans;

    return ans;
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
