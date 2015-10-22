#include "solver.h"

Solver::Solver()
{
}

Solver::Solver(std::vector<int>& ve, int lenthDiv,int maxNum)
{
    this->reciveVectot=ve;
    this->lengtDiv=lenthDiv;
    this->bucket=new std::vector<std::vector<int> >(maxNum/lenthDiv+1);
}

void Solver::Show() const
{
    for(auto& value:reciveVectot )
        std::cout<<value<<" ";
    std::cout<<std::endl;
}

void Solver::BucketDiv()
{
    for(auto value:reciveVectot){
        std::vector<int>&temp= bucket->at(value/lengtDiv);
        temp.push_back(value);
    }
    for(int i=0;i<bucket->size();++i){
        std::vector<int>temp= bucket->at(i);
        temp;
    }
    reciveVectot.clear();
    for(auto& perBucket:*bucket){
        reciveVectot+=perBucket;
    }
}
