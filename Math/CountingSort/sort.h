#ifndef SORT_H
#define SORT_H
#include<QList>
class Sort
{
public:
    Sort(QList<int> A, int max);
    QList<int>  ReturnAns();
private:
    QList<int> A;
    QList<int>  B,Trans;
    int max;

    void CountingSort();

};

#endif // SORT_H
