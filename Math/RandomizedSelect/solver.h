#ifndef SOLVER_H
#define SOLVER_H
#include<QList>

class Solver
{
public:
    Solver(QList<int> const list, int targetLocation);
    void Show();
private:
    QList<int>list;
    int targetLocation;
    void RandomList();
    int Select(int startIndex,int endIndex,int targetLocation);
    int Partition(int startIndex, int endIndex);
};

#endif // SOLVER_H
