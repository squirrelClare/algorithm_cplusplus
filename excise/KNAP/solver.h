#ifndef SOLVER_H
#define SOLVER_H
#include<QList>

class Solver
{
public:
    Solver(QList<int> productionWeight,QList<int>productValue);
private:
    int RecurKnap(const int &presentWeight);
    int productionNum;
    QList<int> productWeight,productValue;
};

#endif // SOLVER_H
