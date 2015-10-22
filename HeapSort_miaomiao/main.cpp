#include <iostream>
#include<vector>
#include"heapsort.h"

using namespace std;
void printVect(const std::vector<int>& vec)
{
    for (int i=0;i<vec.size();++i)
        std::cout<<vec.at(i)<<'\t';
    std::cout<<std::endl;
}
int main()
{
    int arr[10]={121,34,4322,42,422,445,4,56,24,245};
    vector<int> iVec1(arr,arr+10);
    printVect(iVec1);
    HeapSort hSort;
    hSort.BuildHeap(iVec1);
//    hSort.MaxHeap(iVec1,3);

    vector<int>temp=hSort.Sort(iVec1);
    printVect(temp);

    return 0;
}

