#include <iostream>
#include"abstractfactory.h"
using namespace std;

int main()
{
    AbstractFactory* cf1=new ConcreateFactory1();
    cf1->createProductA();
    cf1->createProductB();

    AbstractFactory* cf2=new ConcreateFactory2();
    cf2->createProductA();
    cf2->createProductB();
    return 0;
}

