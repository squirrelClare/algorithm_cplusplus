#include "sortfuction.h"
#include<QDebug>
/**
此算法中利用了QList类,主要是利用其
添加新元素,输出元素,以及更改元素.
可以省去很多时间精简代码,QList本身也
自带了排序功能(sort())*/

SortFuction::SortFuction(QList<int> list)
{
    this->list=list;
}

void SortFuction::Merge(int start, int end, int div)
{
    //对左右两数组做排序
    int count_1=div-start+1;
    int count_2=end-div;

    QList<int>left=list.mid(start,count_1);
    QList<int>right=list.mid(div+1,count_2);
    //设置哨兵
    left.append(10000);
    right.append(10000);

    int flag_l=0;
    int flag_r=0;

    /*类似于把扑克牌分为两堆,每次取上面
     *最小的一张放如一个新的牌堆,直至两
        堆牌全部放入新的牌堆中*/
    for(int i=start;i<=end;i++){
        if(left.at(flag_l)<=right.at(flag_r)){
            list.replace(i,left.at(flag_l));
            flag_l++;
         }else{
             list.replace(i,right.at(flag_r));
             flag_r++;
        }
    }
}

void SortFuction::MergeSort(int start, int end)
{
    /*以索引div为分界,将当前数组分为两个小数组
    当start>=end时,数组最多含有一个元素,固不用排序
    ,此为分治法的终止条件.
    对于每一次的分治:MergeSort(start,div)产生的是
    一个已经排好序的左数组,而MergeSort(div+1,end)
    产生的是一个已经排好序的右数组.Merge(start,end,div)
    则是对上述已经排序还的左右数组进行合并,为分治法
    的后续排序提供一个排序好的数组.*/
    if(start<end){
        int div=(int)(start+end)/2;
        MergeSort(start,div);
        MergeSort(div+1,end);
        Merge(start,end,div);
    }
}

void SortFuction::Show()
{
    //输出排序后的数组
    qDebug()<<list;
}
