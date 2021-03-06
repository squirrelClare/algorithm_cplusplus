﻿#ifndef SOLVER_H
#define SOLVER_H
#include<QList>
#include<QMap>

class BarPart;
class RodAns;
class Solver
{
public:
    Solver();
    Solver(const QList<int> lengthList, const QList<int> valueList, const int totalLength);
    void ShowResult();
private:
    int totalLength;
    QList<int>record;
    QMap<int,BarPart> *barList;
    RodAns BottomUpCutRod(const int totalLength);
};


class BarPart
{
public:
    BarPart();
    BarPart(const int barLength,const int barValue);
    int barLength,barValue;
};

class RodAns{
public:
    int bestValue;
    QList<int>proAns;
};

#endif // SOLVER_H
