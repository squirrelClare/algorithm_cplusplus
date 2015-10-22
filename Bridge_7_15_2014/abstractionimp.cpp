#include "abstractionimp.h"
#include<iostream>
using namespace std;
AbstractionImp::~AbstractionImp()
{

}

void AbstractionImp::operation()
{
    cout<<"AbstractionImp...imp..."<<endl;
}

AbstractionImp::AbstractionImp()
{
}


ConcreateAbstractionImpA::ConcreateAbstractionImpA()
{

}

ConcreateAbstractionImpA::~ConcreateAbstractionImpA()
{

}

void ConcreateAbstractionImpA::operation()
{
    cout<<"ConcreateAbstractionImpA..."<<endl;
}


ConcreateAbstractionImpB::ConcreateAbstractionImpB()
{

}

ConcreateAbstractionImpB::~ConcreateAbstractionImpB()
{

}

void ConcreateAbstractionImpB::operation()
{
    cout<<"ConcreateAbstractionImpB..."<<endl;
}
