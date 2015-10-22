#include "maxheap.h"
#include<QDebug>
MaxHeap::MaxHeap(QList<int>list)
{
    this->list=list;
}

void MaxHeap::BuildMaxHeap()
{
    for(int i=this->list.length()/2;i>0;i--){
        MaxHeapIFY(i);
    }
}

void MaxHeap::MaxHeapIFY(int i)
{
    int l=Left(i);
    int r=Right(i);
    int largest;
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
int MaxHeap::Left(int i){
    return 2*i;
}
int MaxHeap::Right(int i){
    return 2*i+1;
}


void MaxHeap::Show()
{
    qDebug()<<this->list;
}


QList<int> MaxHeap::GetList()
{
    return this->list;
}
