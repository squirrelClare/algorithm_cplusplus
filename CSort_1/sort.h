#ifndef SORT_H
#define SORT_H

class sort
{
public:
    sort(int arry[],int size);
    void BubbleSort();//冒泡排序
    void InsertSort();//插入排序
    void QuickSort(int first,int last);//快速排序,first,last分别代表数组的首尾下标
    int Partition(int first,int last);//数组的划分，返回分点，（分治法）
    void Merge(int first, int p, int last);//将两个有序数组合并成一个有序数组
    void MergeSort(int first,int last);//归并排序
    void CountingSort();//计数排序
    void RadixSort();//基数排序
    void ShowOut();

private:
    int *arry;
    int size;
};

#endif // SORT_H
