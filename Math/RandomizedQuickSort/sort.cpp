#include "sort.h"
#include<QList>
#include<QDebug>
#include<QTime>
Sort::Sort()
{
}

QList<int>  &Sort::Random(QList<int> &list)
{//对输入的数组随机化
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for(int i=0;i<list.length();++i)
    list.swap(qrand()%list.length(),list.length()-1);
    return list;
}

QList<int> &Sort::Quicksort(QList<int> &list, int indexStart, int indexEnd)
{
    int p=-1;
    if(indexStart<indexEnd){
        p=Partition(list,indexStart,indexEnd);
    if(indexStart<(p-1))
        Quicksort(list,indexStart,p-1);
    if(p+1<indexEnd)
        Quicksort(list,p+1,indexEnd);
    }
    return list;
}

int Sort::Partition(QList<int> &list, int indexStart, int indexEnd)
{//快速排序算法主体部分
    int max=list.at(indexEnd);
    int start=indexStart-1;
    for(int j=indexStart;j<indexEnd;j++){
        if(list.at(j)<max){
            start++;
            list.swap(start,j);
        }
    }
    start++;
    list.swap(start,indexEnd);
    return start;
}
