#include "sort.h"
#include<QList>
#include<QDebug>

Sort::Sort()
{
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
{
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
