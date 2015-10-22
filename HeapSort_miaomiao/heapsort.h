#ifndef HEAPSORT_H
#define HEAPSORT_H
#include<vector>
using std::vector;
class HeapSort
{
public:
    HeapSort();
    ~HeapSort();
    void MaxHeap(vector<int> &iVec, int i);
    void BuildHeap(vector<int> &iVec);
    vector<int> Sort(vector<int> iVec);
    void swap(int &value1,int &value2);
    void VecOutPut(vector<int> &iVec);
};

#endif // HEAPSORT_H
