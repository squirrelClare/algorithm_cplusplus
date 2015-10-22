#ifndef Solver_H
#define Solver_H
#include<QMap>
#include"barpart.h"

class Solver
{
public:
    Solver(const QList<int> lengthList, const QList<int> valueList, const int totalLength);
    void ShowResult();
private:

    int totalLength;
    QMap<int,BarPart> *barList;
    int CutRod(const int totalLength);
};

#endif // Solver_H
