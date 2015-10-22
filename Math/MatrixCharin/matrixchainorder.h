#ifndef MATRIXCHAINORDER_H
#define MATRIXCHAINORDER_H
#include<QVector>
#include<QPair>
#include<QString>
/**矩阵链乘法：
    1.对给定的矩阵链求出最佳的加括号方案
    2.MatrixChainOrder是一个函数类*/
class MatrixChainOrder
{
public:
    MatrixChainOrder(QVector<int> *vec);
    QPair<int,QString> operator ()();//返回最少乘法次数和加括号方案
    void Print(int i, int j);//求解括号方案
private:
    QVector<int>* vec;//接受原始矩阵链
    QVector<QVector<int>* >* m;//存储局部乘法最优解
    QVector<QVector<int>* >* s;//存储局部最优加括号方案
    QString  str;

};

#endif // MATRIXCHAINORDER_H
