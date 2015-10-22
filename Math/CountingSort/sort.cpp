#include "sort.h"
#include<QDebug>
Sort::Sort(QList<int> A, int max)
{
    this->A=A;
    for(int i=0;i<A.length();i++){
        B.append(0);
    }
    this->max=max;
    for(int i=0;i<=max;i++){
        Trans.append(0);
    }
}

QList<int> Sort::ReturnAns()
{

    CountingSort();
    return this->B;
}


void Sort::CountingSort()
{
    for(int i=0;i<A.length();i++){
        int mid=A.at(i);
        Trans.replace(mid,Trans.at(mid)+1);
    }
    for(int i=1;i<=max;i++){
        Trans.replace(A.at(i),A.at(i)+A.at(i-1));
    }
     qDebug()<<Trans;
    for(int i=A.length()-1;i>-1;i--){
        B.replace(Trans.at(A.at(i))-1,A.at(i));
        Trans.replace(A.at(i),Trans.at(A.at(i))-1);
    }
}
