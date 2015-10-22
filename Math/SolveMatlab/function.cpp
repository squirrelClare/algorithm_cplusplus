#include "function.h"
#include<QtCore>
Function::Function()
{
    a=(105-23*qSqrt(21))/14;
    b=(105+23*qSqrt(21))/14;
    c=(151*qSqrt(21)-693)/294;
    d=(151*qSqrt(21)+693)/294;
    e=(5*qSqrt(21)-23)/14;
    f=(5*qSqrt(21)-23)/14;
    m=(qSqrt(21)-5)/2;
    n=(-qSqrt(21)-5)/2;
}

QList<double> Function::ReturnAns()
{
    this->Slove();
    return this->list;
}

void Function::Slove()
{
    double result;
    for(int g=1;g<11;g++){
        result=((b*qPow(g,2)+(12*f+2*b)*g+12*d)*qPow(n,g-1)
                  -(-a*qPow(g,2)+(12*e-2*a)*g+12*c)*qPow(m,g-1))
                /(2*(3*g+2)*(a*qPow(m,g-1)+b*qPow(n,g-1)));
        this->list.append(result);
    }
}
