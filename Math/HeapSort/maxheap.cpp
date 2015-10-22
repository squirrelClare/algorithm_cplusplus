#include "maxheap.h"
#include<QDebug>
MaxHeap::MaxHeap(QList<int>list)
{//构造函数
    this->list=list;
}

void MaxHeap::BuildMaxHeap()
{//构造堆
    for(int i=this->list.length()/2;i>0;i--){
        MaxHeapIFY(i);
    }
}

void MaxHeap::MaxHeapIFY(int i)
{//最大堆排序
    int l=Left(i);
    int r=Right(i);
    int largest;

    //寻找list[i],list[l],list[r]三者间的最大值
    if((l<=this->list.length())&&((r<=this->list.length()))&&
            (this->list.at(l-1)>this->list.at(i-1))&&(this->list.at(l-1)>this->list.at(r-1))){
        this->list.swap(l-1,i-1);
        largest=l;
    }else if((r<=this->list.length())&&(l<=this->list.length())&&
             (this->list.at(r-1)>this->list.at(i-1))&&(this->list.at(r-1)>this->list.at(l-1))){
            this->list.swap(r-1,i-1);
            largest=r;
    }
    else{
        largest=i;
    }
    if(largest!=i&&largest<=this->list.length())
    MaxHeapIFY(largest);


}
int MaxHeap::Left(int i){//求i的子节点的index
    return 2*i;
}
int MaxHeap::Right(int i){//求i的子节点的index
    return 2*i+1;
}


void MaxHeap::Show()
{//打印list数组
    qDebug()<<this->list;
}


QList<int> MaxHeap::GetList()
{//返回排序后的数组
    return this->list;
}
