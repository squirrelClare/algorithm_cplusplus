#include "solver.h"
#include<QDebug>
Solver::Solver()
{
}

Solver::Solver(QList<int> list,int lengthDiv,int bucketNum)
{
    //list原始数组，lengthDiv桶的绝对容积，区别于桶内元素的个数。
    this->list=list;
    this->lengthDiv=lengthDiv;
    this->bucketNum=bucketNum;
}

void Solver::Show()
{
    qDebug()<<"输入的原始数组是："<<list;
    qDebug()<<"经过桶排序后的数组是:"<<BucketDiv(lengthDiv,bucketNum);

}

QList<int> Solver::BucketDiv(int lengthDiv,int bucketNum)
{
    QMap<int,Bucket>temporaryBucket;

    //初始化bucketNum个桶
    for(int i=0;i<=bucketNum;++i){
        Bucket list;
        temporaryBucket.insert(i,list);
    }

    //将原始数据分到不同的桶中.
    for(int i=0;i<list.length();++i){
        int index=(int)(list.at(i)/lengthDiv);//求出数值对应的桶号

        //将数值装入桶中
        Bucket bucket;
        bucket=temporaryBucket.value(index);//QMap中的value返回类型是const T
        bucket.append(list.at(i));
        temporaryBucket.insert(index,bucket);

    }

    //对每个桶中元素进行排序
    for(int i=0;i<=bucketNum;++i){
        Bucket bucket=temporaryBucket.value(i);
        InsertSort(bucket);
        temporaryBucket.insert(i,bucket);
    }

    //合并各个桶中的数据
    QList<int>temporaryList;
    for(int i=0;i<=bucketNum;++i){
        temporaryList=temporaryList+temporaryBucket.value(i);
    }
    return temporaryList;
}

void Solver::InsertSort(Bucket& list)
{
    //对单个桶中的元素进行插入排序
    for(int i=0;i<list.length();++i){
        int trans=list.at(i);
        for(int j=i-1;j>=0;--j){
            if(list.at(j)>list.at(i))
                list.replace(j+1,list.at(j));
            else{
                list.replace(j+1,trans);
                break;
            }
        }
    }
}
