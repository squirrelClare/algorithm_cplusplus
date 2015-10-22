#include "solver.h"

Solver::Solver()
{
}

QString Solver::MaxNum(const QList<int> list)
{//比较n-1次求出数组的最大值.
    int max=list.at(0);
    for(int i=1;i<list.length();++i){
        if(list.at(i)>max)
            max=list.at(i);
    }
    return QString("The maxNum is %1").arg(max);
}

QString Solver::MinNum(const QList<int> list)
{//比较n-1次求出数组的最小值
    int min=list.at(0);
    for(int i=1;i<list.length();++i){
        if(list.at(i)<min)
            min=list.at(i);
    }
    return QString("The minNum is %1").arg(min);
}

QString Solver::MNum(const QList<int> list)
{//比较O(3/2*n)次求出数组的最大值和最小值

    int min,max,starIndex;//min存数组的最小值,max存数组的最大值,
                            //starIndex后续迭代初始索引值.

    bool flag=list.length()%2;//判断数组元素个数奇偶性

    if(flag){
        //数组元素个数为偶数时,迭代初始参数设定
        if(list.at(0)>list.at(1)){
            min=list.at(1);
            max=list.at(0);
        }else{
            min=list.at(0);
            max=list.at(1);
        }
        starIndex=2;
    }else{
        //数组个数为奇数时,迭代参数设定
        min=list.at(0);
        max=list.at(0);
        starIndex=1;
    }

    for(int i=starIndex;i<list.length()-1;i+=2){
        int currentMin=0,currentMax=0;//初始化currentMin,currentMax

        //currentMin存储新传入一对值得最小值,currentMax存储新传入一对值得最大值.
        //第一次比较
        if(list.at(i)<list.at(i+1)){
            currentMax=list.at(i+1);
            currentMin=list.at(i);
        }else{
            currentMax=list.at(i);
            currentMin=list.at(i+1);
        }

        //第二次比较,将currentMin同min比较获取最小值
        if(currentMin<min)
            min=currentMin;

        //第三次比较,将currentMax同max比较获取最大值
        if(currentMax>max)
            max=currentMax;
    }
    return QString("The maxNum is %1,the minNum is %2")
            .arg(max).arg(min);
}
