#include "sort.h"
#include<QTextStream>

sort::sort(int arry[], int size)
{
    this->arry=arry;
    this->size=size;
}

void sort::BubbleSort()//冒泡排序
{
    int temp;
    for(int i=0;i<size-1;++i)
        for(int j=0;j<size-1-i;++j)
            if(arry[j]>arry[j+1]){
                temp=arry[j];
                arry[j]=arry[j+1];
                arry[j+1]=temp;
            }

}

void sort::InsertSort()//插入排序
{
    int i;
    int key;
    for(i=1;i<size;++i){
        key=arry[i];
        for(int j=i-1;j>=0;j--){
            if(arry[j]>key){
                arry[j+1]=arry[j];
                arry[j]=key;
            }
            else {
                arry[j+1]=key;
                break;

            }
        }
    }

}

void sort::QuickSort(int first, int last)//快速排序
{
    if(first<last){
        int q=Partition(first,last);
        QuickSort(first,q-1);
        QuickSort(q+1,last);
    }
}


int sort::Partition(int first, int last)//数组的划分
{
    int i,j;
    int x;
    int change;
    x=arry[last];
    i=first-1;
    for(j=first;j<last;++j){
        if(arry[j]<x){
            i=i+1;
            change=arry[i];
            arry[i]=arry[j];
            arry[j]=change;
        }
    }
    change=arry[i+1];
    arry[i+1]=arry[last];//arry[last]不能用x代替：交换数组中元素的值，x不是数组中的元素，x只是与arry[last]相等的数
    arry[last]=change;
    return i+1;
}

void sort::Merge(int first,int p,int last)
{
    int *arry_1=new int[p-first+1+1];
    int *arry_2=new int[last-p+1];
    for(int i=0;i<p-first+1;++i){
        arry_1[i]=arry[first+i];
    }
    arry_1[p-first+1]=100000;

    for(int i=0;i<last-p;++i){
        arry_2[i]=arry[i+p+1];
    }
    arry_2[last-p]=100000;

    int k=first;
    int i=0,j=0;

    while(i<p-first+2&&j<last-p+1&&k<=last){
        if(arry_1[i]<arry_2[j]){
            arry[k]=arry_1[i];
            k++;
            i++;
        }else{
            arry[k]=arry_2[j];
            k++;
            j++;
        }
    }
   /* while(i<p-first+1){
        arry[k]=arry_1[i];
        k++;
        i++;
    }
    while(j<last-p){
        arry[k]=arry_2[j];
        k++;
        j++;
    }*/

}


void sort::MergeSort(int first, int last)
{
    if(first<last){
        int p=(first+last)/2;
        MergeSort(first,p);
        MergeSort(p+1,last);
        Merge(first,p,last);
    }
}

void sort::CountingSort()//计数排序
{
    int max=arry[0];
    for(int i=1;i<size;++i){
        if(max<arry[i])
            max=arry[i];
    }
    int *count=new int[max+1];
    for(int i=0;i<max+1;++i){//初始化
        count[i]=0;
    }
    for(int i=0;i<size;++i){//count[arry[i]]储存arry[i]的个数
        count[arry[i]]++;
    }
    for(int i=1;i<max+1;++i){//count[arry[i]]储存不大于arry[i]的个数
        count[i]+=count[i-1];
    }
    int *temp=new int[size];//存放排好序的元素
    for(int i=size-1;i>=0;--i){
        count[arry[i]]-=1;
        temp[count[arry[i]]]=arry[i];

    }
    for(int i=0;i<size;++i){//输出的数组是arry，所以再返回给arry
        arry[i]=temp[i];
    }
}

void sort::RadixSort()//基数排序
{
    int *index=new int[size];
    for(int i=0;i<size;++i){//为存储各元素位数的数组index赋初值
        index[i]=0;
    }
    int base=1;
    bool IsOk=false;//判断排序是否完成
    while(!IsOk){//从数组元素最右边列的数值开始排序
        IsOk=true;
        base*=10;
        for(int i=0;i<size;++i){//提取数组元素某一列的值,分别记在index[i]中
            index[i]=arry[i]%base;
            index[i]/=(base/10);
            if(arry[i]/base)//如果该列元素不全为0，则排序未结束
                IsOk=false;
            }

        if(IsOk){
            break;
        }

        int temp;//冒泡排序，arry随着index一起交换
        for(int i=0;i<size-1;++i)
            for(int j=0;j<size-1-i;++j)
                if(index[j]>index[j+1]){
                    temp=arry[j];
                    arry[j]=arry[j+1];
                    arry[j+1]=temp;
                    temp=index[j];
                    index[j]=index[j+1];
                    index[j+1]=temp;
                }
    }



}

void sort::ShowOut()
{
    QTextStream out(stdout);
    for(int i=0;i<size;++i){
        out<<arry[i]<<" ";
        out.flush();
    }
    out<<endl;
}
