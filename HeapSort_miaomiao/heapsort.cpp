#include "heapsort.h"
#include<iostream>
using namespace std;

HeapSort::HeapSort()
{

}

HeapSort::~HeapSort()
{

}

void HeapSort::MaxHeap(vector<int>& iVec, int i)
{
    int left=2*i+1;
    int right=2*i+2;
    int larger;

    if(left<iVec.size()&&iVec.at(left)>iVec.at(i)){
        larger=left;
    }else{
        larger=i;
    }
//    if(right<=iVec.size()&&iVec.at(right)>iVec.at(larger)){
//        larger=right;
//    }//此部分为原始部分
       if(right<iVec.size()&&iVec.at(right)>iVec.at(larger)){
           larger=right;
       }

    if(larger<iVec.size()&&larger!=i){
        swap(iVec.at(larger),iVec.at(i));
        MaxHeap(iVec,larger);
    }
}

void HeapSort::BuildHeap(vector<int>& iVec)
{
//    for(int i=(iVec.size())/2;i>=0;--i)
//        MaxHeap(iVec,i);
    for(int i=(iVec.size())/2;i>=0;--i)
        MaxHeap(iVec,i);
}

vector<int> HeapSort::Sort(vector<int> iVec)
{
    vector<int> temp;
    //int length=iVec.size();
    for(int i=iVec.size()-1;i>=0;--i){
        swap(iVec.at(0),iVec.at(i));
        temp.push_back(iVec.at(iVec.size()-1));
        iVec.pop_back();
        MaxHeap(iVec,0);
    }
    return temp;
}

void HeapSort::swap(int &value1, int &value2)
{
    int temp;
    temp=value1;
    value1=value2;
    value2=temp;

}

void HeapSort::VecOutPut(vector<int> &iVec)
{
    for(vector<int>::iterator it=iVec.begin();it!=iVec.end();++it)
        cout<<*it<<" ";
    cout<<endl;

}

