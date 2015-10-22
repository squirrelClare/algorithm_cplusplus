#include <iostream>
#include<functional>
#include"MyFunction.h"

using namespace std;

double Add(double lhs,double rhs)
{
    return lhs+rhs;
}

double Multiply(double lhs,double rhs)
{
    return lhs*rhs;
}

double BinaryOper(double lhs,double rhs,double f(double,double))
{
    return f(lhs,rhs);
}


function<int(int,int)> f=[](int lhs,int rhs)->int{return lhs-rhs;};

int main()
{
    cout << "add" <<BinaryOper(5.26,4.56,Add)<< endl;
    cout << "Multiply" <<BinaryOper(5.26,4.56,Multiply)<< endl;
    cout<<f(9,7)<<endl;

    MyFunction* f=new MyFunction(2,3);
    cout<<(*f)(2,3)<<endl;

    return 0;
}

