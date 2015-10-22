#include <iostream>
#include"abstraction.h"
#include"abstractionimp.h"
using namespace std;

int main()
{
    AbstractionImp* imp=new ConcreateAbstractionImpA();
    Abstraction* abs=new RefinedAbstraction(imp);
    abs->operation();
    return 0;
}

