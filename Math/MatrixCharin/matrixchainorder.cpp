#include "matrixchainorder.h"
#include<QTextStream>
#include<QString>
MatrixChainOrder::MatrixChainOrder(QVector<int>* vec)
{
    this->vec=vec;
    int n=vec->size()-1;

    //初始化m,s
    this->m=new QVector<QVector<int>*>(n+1);
    this->s=new QVector<QVector<int>*>(n+1);
    for(int i=0;i<n+1;++i){
        (*m)[i]= new QVector<int>(n+1,1900000);
        (*s)[i]= new QVector<int>(n+1,-1);
    }

    for(int i=0;i<n+1;++i)
        (*(*m)[i])[i]=0;
}

QPair<int, QString> MatrixChainOrder::operator ()()
{
    //从底部往上回溯的构建局部乘法最优解方案供后续调用
    int n=vec->size()-1;
    for(int leng=2;leng<=n;++leng){//设置局部矩阵链长度
        for(int i=1;i<=n-leng+1;++i){//设置局部矩阵链起始下标识及其范围
           int j=i+leng-1;
           int q=-1;
           for(int k=i;k<=j-1;++k){//穷举固定矩阵链下的括号方案
               q=(*(*m)[i])[k]+(*(*m)[k+1])[j]+(vec->at(i-1))*(vec->at(k))*(vec->at(j));
               //求解固定矩阵链下的最优加括号方案
               if(q<(*(*m)[i])[j]){
                   (*(*m)[i])[j]=q;
                   (*(*s)[i])[j]=k;
               }
            }
        }
    }

    //求解最优加括号方案
    Print(1,n);
    QPair<int,QString> r((*(*m)[1])[n],str);//保存结果并输出
    return r;
}

void MatrixChainOrder::Print( int i, int j)
{
    //使用递归输出最优加括号方案，保存至函数类的str中
    if (i==j){
        str.append("A").append(QString::number(i));
    }else{
        str.append("(");
        Print(i,(*(*s)[i])[j]);
        Print((*(*s)[i])[j]+1,j);
         str.append(")");
    }
}

