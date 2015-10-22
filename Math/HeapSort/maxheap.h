#ifndef MAXHEAP_H
#define MAXHEAP_H
#include<QList>
class MaxHeap
{
public:
    MaxHeap(QList<int>list);
    void BuildMaxHeap();
    void Show();
    QList<int> GetList();
private:
    QList<int>list;
    void MaxHeapIFY(int i);
    int Left(int i);
    int Right(int i);
    void Swap(int max, int min, QList<int> A);
};

#endif // MAXHEAP_H
