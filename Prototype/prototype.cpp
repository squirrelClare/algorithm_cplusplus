#include "prototype.h"
#include<iostream>
using namespace std;
Prototype::~Prototype()
{

}

Prototype::Prototype()
{

}


ConcreatePrototype::ConcreatePrototype()
{

}

ConcreatePrototype::ConcreatePrototype(const ConcreatePrototype *cp)
{
    cout<<"ConcreatePrototype copy..."<<endl;
}

ConcreatePrototype::~ConcreatePrototype()
{

}

Prototype *ConcreatePrototype::clone() const
{
    return new ConcreatePrototype(this);
}
