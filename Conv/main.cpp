#include <QCoreApplication>
#include<QVector>
#include<QDebug>
QVector<int> Conv(const QVector<int>&x,const QVector<int>&y);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QVector<int> x({3 ,1, 4, 2});
    QVector<int> y({23,3,23,13});
    qDebug()<<x<<endl<<y<<endl;
    qDebug()<<Conv(x,y)<<endl;
    qDebug()<<Conv(y,x)<<endl;
    return a.exec();
}
QVector<int> Conv(const QVector<int>&x,const QVector<int>&y)
{
    QVector<int> temp;
    int res=0;
    for(size_t n=0;n<x.size();++n)
    {
        for(size_t k=0;k<=n;++k)
        {
            res+=x.at(k)*y.at(n-k);
        }
        temp.push_back(res);
        res=0;
    }
    return temp;
}
