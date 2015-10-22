#ifndef MYFUNCTION_H
#define MYFUNCTION_H

class MyFunction
{
public:
    MyFunction(int v1,int v2):a(v1),b(v2)
    {
    };
    int operator()(int lhs,int rhs)
    {
        return a*lhs+b*rhs;
    };

private:
    int a;
    int b;
};

#endif // MYFUNCTION_H
