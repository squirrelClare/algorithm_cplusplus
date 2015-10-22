#ifndef SORTOR_H
#define SORTOR_H
#include<vector>

class Sortor
{
public:
    Sortor();

    static  void BulidHeap(std::vector<int>& vec);
    static  void MaxHeap(std::vector<int>&vec,int index);
    static  std::vector<int> HeapSort(std::vector<int>&vec);
};

#endif // SORTOR_H
