#include "sortor.h"
#include<iostream>
Sortor::Sortor()
{
}

void Sortor::BulidHeap(std::vector<int> &vec)
{
    for (int i=vec.size()/2;i>0;--i){
        MaxHeap(vec,i);
    }
}

void Sortor::MaxHeap(std::vector<int> &vec, int index)
{

    int leftIndex=2*index-1;
    int rightIndex=2*index;
    index=index-1;
    int indexOfMax;

    if (leftIndex<vec.size()&&vec.at(leftIndex)>vec.at(index))
    {
        indexOfMax=leftIndex;
    }else {
        indexOfMax=index;
    }

    if (rightIndex<vec.size()&&vec.at(rightIndex)>vec.at(indexOfMax)){
        indexOfMax=rightIndex;
    }

    if (indexOfMax<vec.size()&&indexOfMax!=index){
        int temp=vec.at(index);
        vec.at(index)=vec.at(indexOfMax);
        vec.at(indexOfMax)=temp;
        MaxHeap(vec,indexOfMax+1);
    }
}


std::vector<int> Sortor::HeapSort(std::vector<int> &vec)
{
    BulidHeap(vec);
    std::vector<int> result;
    for (int i=vec.size();i>0;--i){
        result.push_back(vec.at(0));
        vec.at(0)=vec.at(vec.size()-1);
        vec.pop_back();
        MaxHeap(vec,1);
    }
    return result;
}







