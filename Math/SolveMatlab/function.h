#ifndef FUNCTION_H
#define FUNCTION_H
#include<QList>

class Function
{
public:
    Function();
    QList<double> ReturnAns();
private:
    double a,b,c,d,e,f,m,n;
    QList<double>list;
    void Slove();
};

#endif // FUNCTION_H
