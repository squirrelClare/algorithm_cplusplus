#ifndef SORTFUCTION_H
#define SORTFUCTION_H
#include<QDebug>
#include<QList>

class SortFuction
{
public:
    SortFuction(QList<int>list);
    void MergeSort(int  start,int end);
    void Show();
private:
    QList<int>list;
    void Merge(int start,int end,int div);
};

#endif // SORTFUCTION_H
