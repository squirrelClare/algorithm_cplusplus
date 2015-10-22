#ifndef SORT_H
#define SORT_H
#include<QList>
class Sort
{
public:
    Sort();
    QList<int> &Quicksort(QList<int> &list,int indexStart,int indexEnd);
    int Partition(QList<int> &list,int indexStart,int indexEnd);
};

#endif // SORT_H
