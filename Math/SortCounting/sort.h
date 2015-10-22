#ifndef SORT_H
#define SORT_H

class Sort
{
public:
    Sort(int *transIn,int max);
    void Show();
private:
    int max;
    int *transIn,*outValue,*midValue;

    void CountingSort();
    void ShowList(int *value);
};

#endif // SORT_H
