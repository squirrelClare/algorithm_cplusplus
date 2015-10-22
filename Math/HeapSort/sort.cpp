#include "sort.h"

Sort::Sort(QList<int> list)
{//接收待排序的数组
    this->list=list;
    result=list;
}

QList<int> Sort::GetResult()
{//返回快速排序后的数组
    return result;
}


void Sort::ListSort()
{//数组排序
    for(int i=list.length();i>1;i--){
        //对重载后的list进行最大堆排序
        heap=new MaxHeap(this->list);
        heap->BuildMaxHeap();
        list=heap->GetList();
        //交换最大堆排序后的最大值与末尾值的位置
        list.swap(0,i-1);
        //将每次最大堆排序后的最大值存入result数组中相应的位置,并刷新list数组中的元素构成
        result.replace(i-1,list.takeAt(i-1));
        delete heap;
    }
}
