#ifndef SORT_H
#define SORT_H
#include<QList>
#include"maxheap.h"

class Sort
{
public:
    Sort(QList<int>list);
    QList<int> GetResult();
    void ListSort();
private:
    QList<int>list;
    QList<int>result;
    MaxHeap *heap;
};

#endif // SORT_H
