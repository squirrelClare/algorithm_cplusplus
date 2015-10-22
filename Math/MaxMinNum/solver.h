#ifndef SOLVER_H
#define SOLVER_H
#include<QList>
#include<QString>

class Solver
{
public:
    Solver();
    static QString MaxNum(const QList<int> list);
    static QString MinNum(const QList<int> list);
    static QString MNum(const QList<int> list);
private:
    QList<int>list;
};

#endif // SOLVER_H
