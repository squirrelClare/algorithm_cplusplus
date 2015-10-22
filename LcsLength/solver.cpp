#include "solver.h"
#include<QDebug>
Solver::Solver()
{
}

void Solver::PrintLcs()
{
    for(int i=0;i<mC->size();++i){
        qDebug()<<mC->at(i);
    }
    qDebug()<<"**************************";

    for(int j=0;j<mB->size();++j){
        qDebug()<<mB->at(j);
    }
    qDebug()<<"Done!!";
}

void Solver::LcsLength(QVector<int> X, QVector<int> Y)
{
    //初始化
    //X为两个列所生成的局部最长公共子列数
    //Y为对应方向图
    int m=X.size();
    int n=Y.size();

    this->mC=new QVector<QVector<int> >();
    this->mB=new QVector<QVector<QString> >();

    for(int i=0;i<m+1;++i){
        mC->append(QVector<int>(n+1,0));
        mB->append(QVector<QString>(n+1,"NULL"));
    }

    for(int i=1;i<=m;++i){
        (*mC)[i][0]=0;
    }
    for(int j=0;j<=n;++j){
        (*mC)[0][j]=0;
    }

    //求解主题步骤
    /*U=上,L=左,LU=左上*/
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(X.at(i-1)==Y.at(j-1)){
                (*mC)[i][j]=1+(*mC)[i-1][j-1];
               (*mB)[i][j]="LU";
            }else if ((mC->at(i-1).at(j))>=(mC->at(i).at(j-1))) {
               (*mC)[i][j]=(*mC)[i-1][j];
                (*mB)[i][j]=QString("U");
            }else{
                (*mC)[i][j]=(*mC)[i][j-1];
               (*mB)[i][j]=QString("L");
            }
        }
    }
}
