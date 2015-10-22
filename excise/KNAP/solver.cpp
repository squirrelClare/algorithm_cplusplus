#include "solver.h"

Solver::Solver(QList<int> productWeight, QList<int> productValue)
{
    this->productWeight=productWeight;
    this->productValue=productValue;
    productionNum=productWeight.length();
}

int Solver::RecurKnap(const int &presentWeight)
{
    int max=0;
    for(int i=0;i<productionNum;++i){
        int weightLeft=presentWeight-productWeight.at(i);
        int laterBest=RecurKnap(weightLeft)+productValue.at(i);
        if(weightLeft>=0&&laterBest>max)
            max=laterBest;
    }
    return max;
}
