#include "abstraction.h"
#include"abstractionImp.h"
Abstraction::~Abstraction()
{

}

Abstraction::Abstraction()
{

}


RefinedAbstraction::RefinedAbstraction(AbstractionImp *imp)
{
    this->_imp=imp;
}

RefinedAbstraction::~RefinedAbstraction()
{

}

void RefinedAbstraction::operation()
{
    this->_imp->operation();
}
