#include "solver.h"
#include<QTime>
#include<QDebug>

/**
 *求解数组中排第targetLocation小的元素*/

Solver::Solver(const QList<int> list,int targetLocation)
{
    //初始化:获取传入的list以及targetLocation的值
    this->list=list;
    this->targetLocation=targetLocation;
    RandomList();//对数组进行随机化处理
}

void Solver::Show()
{
    //输出处理后的结果
    qDebug()<<"The list is"<<list;
    qDebug()<<QString("The index of %1 when it is sorted is %2")
              .arg(targetLocation).arg(Select(0,list.length()-1,targetLocation));

}

void Solver::RandomList()
{
    //随机化数组
    for(int i=0;i<list.length();++i){
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));//设置当前时间为随机种子
        list.swap(qrand()%list.length(),list.length()-1);//将随机到的每一个元素值同最后一个进行交换
    }
}

int Solver::Select(int startIndex, int endIndex, int targetLocation)
{
    //如果局部数组只剩下一个数据则直接输出
    if(startIndex==endIndex)return list.at(startIndex);

    int divIndex=-1;//设置快速排序返回的索引值存储变量divIndex,并初始化为-1
    divIndex=Partition(startIndex,endIndex);

    //如果divIndex+1==targetLocation则直接返回list.at(divIndex)
    if(divIndex+1==targetLocation)return list.at(divIndex);

    if(divIndex+1<targetLocation)
        //在右侧继续搜索
        return Select(divIndex+1,endIndex,targetLocation);
    else
        //在左侧继续搜索
        return Select(startIndex,divIndex-1,targetLocation);
}


int Solver::Partition(int startIndex,int endIndex)
{//快速排序
    int target=list.at(endIndex);
    int i=startIndex-1;

    for(int j=startIndex;j<endIndex;j++){
        if(list.at(j)<target){
            ++i;
            list.swap(i,j);
        }
    }
    ++i;
    list.swap(i,endIndex);
    return i;

}
