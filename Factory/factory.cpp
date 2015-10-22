#include "factory.h"
#include"product.h"
#include<iostream>
Factory::~Factory()
{

}

Product *Factory::createProduct()
{

}

Factory::Factory()
{
}


ConcreateFactory::~ConcreateFactory()
{

}

ConcreateFactory::ConcreateFactory()
{
    std::cout<<"ConcreateFactory..."<<std::endl;
}

Product *ConcreateFactory::createProduct()
{
    return new ConcreateProduct();
}
