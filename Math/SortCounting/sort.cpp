#include "sort.h"
#include<QDebug>
#include<QList>
#include<iostream>
Sort::Sort(int *transIn,int max)
{
    this->transIn=transIn;
    this->max=max;
    this->midValue=new int[9];
    this->outValue=new int[8];
}

void Sort::Show()
{
    CountingSort();
    ShowList(transIn);
    ShowList(outValue);
}

void Sort::ShowList(int *value)
{
    QList<int>list;
    for(int i=0;i<8;i++){
        list.append(value[i]);
    }
    qDebug()<<list;
}

void Sort::CountingSort()
{
    for(int i=0;i<8;i++)
        midValue[transIn[i]]=midValue[transIn[i]]+1;
    for(int i=1;i<=9;i++)
        midValue[i]=midValue[i]+midValue[i-1];
    for(int i=7;i>-1;i--){
        outValue[midValue[transIn[i]]-1]=transIn[i];
        midValue[transIn[i]]=midValue[transIn[i]]-1;
    }
}
