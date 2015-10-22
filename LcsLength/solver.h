#ifndef SOLVER_H
#define SOLVER_H
#include<QVector>
#include<QString>

class Solver
{
public:
    Solver();
    void PrintLcs();
    void LcsLength(QVector<int> X,QVector<int> Y);

private:
    QVector<QVector<int> >*  mC;//QVector用[]来访问内部元素的前提是时以对象形式去使用,用指针时则需要用“*”进行解除引用；
    QVector<QVector<QString> >* mB;

};

#endif // SOLVER_H
