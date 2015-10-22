#ifndef SOLVER_H
#define SOLVER_H
#include<QList>
#include<QMap>

class BarPart;
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
    int MemoizedCutRodAux(const int totalLength);
    int MemoizedCutRod(const int totalLength);
};


class BarPart
{
public:
    BarPart();
    BarPart(const int barLength,const int barValue);
    int barLength,barValue;
};


#endif // SOLVER_H
