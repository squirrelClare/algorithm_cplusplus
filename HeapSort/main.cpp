#include <iostream>
#include<iostream>
#include<vector>
#include"sortor.h"
int main()
{
    std::vector<int> vec;
    vec.push_back(16);
    vec.push_back(14);
    vec.push_back(10);
    vec.push_back(8);
    vec.push_back(7);
    vec.push_back(9);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(1);
    for (std::vector<int>::const_iterator it=vec.begin();it!=vec.end();++it){
        std::cout<<*it<<'\t';
    }
//    Sortor::BulidHeap(vec);
//    for (std::vector<int>::const_iterator it=vec.begin();it!=vec.end();++it){
//        std::cout<<*it<<'\t';
//    }
    std::vector<int>res=Sortor::HeapSort(vec);
    for (std::vector<int>::const_iterator it=res.begin();it!=res.end();++it){
        std::cout<<*it<<'\t';
    }
    return 0;
}

