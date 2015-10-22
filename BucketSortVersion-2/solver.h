#ifndef SOLVER_H
#define SOLVER_H
#include<vector>
#include<iostream>
class Solver
{
public:
    Solver();
    Solver(std::vector<int> &ve, int lenthDiv=10, int maxNum=1000);
    virtual void Show()const;
    virtual void BucketDiv();
protected:

    std::vector<std::vector<int> > *bucket;
    std::vector<int> reciveVectot;
    int lengtDiv;//桶的区间长度
};

#endif // SOLVER_H
