#ifndef SOLVER_H
#define SOLVER_H
#include<QList>

typedef QList<int> Bucket;
class Solver
{
public:
    Solver();
    Solver(QList<int>list, int lengthDiv,int bucketNum);
    void Show();//输出排序后的数组
private:
    QList<int>list;
    int lengthDiv;
    int bucketNum;

    QList<int> BucketDiv(int lengthDiv, int bucketNum);//将原始数据分到不同的桶中
    void InsertSort(Bucket &list);//对桶中的数据进行排序
};

#endif // SOLVER_H
