#include <iostream>
#include"prototype.h"
using namespace std;

int main()
{
    Prototype* p=new ConcreatePrototype();
    Prototype* p1=p->clone();
    return 0;
}

