#include <QCoreApplication>
#include<QDebug>
#include<qvector.h>
#include<qstring.h>
#include<vector>
#include<iostream>
#include"myclass.h"
template<class T>
T Add(const  T a,const T  b);
double Fibonacii(double n);
QVector<double> Fibonacii1(int n);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int sum=Add(45,67);
    QString s=Add(QString("dew"),QString("3123"));
    char s1=Add('a','f');
    qDebug()<<sum<<"   "<<s<<"  "<<(int)s1<<endl;

    QVector<int> vec(23,95);
    qDebug()<<vec<<endl;
    int p[]={21,34,5465,78,7,9,9,24,43,4324,67};
    std::vector<int> vec1(p,p+11);
    foreach (auto i, vec1) {
        std::cout<<i<<'\t';
    }
    //1 1 2 3 5 8

    qDebug()<<endl<<    Fibonacii(100)<<endl;
    qDebug()<<Fibonacii1(100);

    QVector<MyClass*> vec2;
    for (int i=0;i<21;++i){
        vec2.push_back(new MyClass());
    }
    qDebug()<<"MyClass的个数为:"<<MyClass::GetNum();//计数,有多少个MyClass被创建
    MyClass* p1=new MyClass();
    MyClass* p2=new MyClass();
    MyClass* p3=new MyClass();
    qDebug()<<"MyClass的个数为:"<<MyClass::GetNum();//计数,有多少个MyClass被创建
    delete p1;
    delete p2;
    qDebug()<<"MyClass的个数为:"<<MyClass::GetNum();//计数,有多少个MyClass被创建

    return a.exec();
}
//斐波那契数列
template<class T>
T Add(const  T lhs,const T rhs)//引用就是给变量一个绰号,小名
{
    return lhs+rhs;
}

double Fibonacii(double n){//带备忘机制的递归
    double sum=0;
    static QVector<double> db(n,0);
    if(n==1||n==2){
        db[n-1]=1;
        return 1;
    }

     double lhs=0;
     double rhs=0;

     if(db[n-2]!=0){
          lhs=db[n-2];
      }else{
          lhs=Fibonacii(n-1);
      }

     if(db[n-3]!=0){
          rhs=db[n-3];
      }else{
          rhs=Fibonacii(n-2);
      }

    sum=lhs+rhs;
    db[n-1]=sum;
    return sum;
}
QVector<double> Fibonacii1(int n){
    QVector<double> vec(n,1);
    for(size_t i=2;i<vec.length();++i){
        vec[i]=vec[i-1]+vec[i-2];
    }
    return vec;
}
