#include "abstractfactory.h"
#include<iostream>
#include"product.h"
AbstractFactory::~AbstractFactory()
{

}

AbstractFactory::AbstractFactory()
{
}


ConcreateFactory1::ConcreateFactory1()
{

}

ConcreateFactory1::~ConcreateFactory1()
{

}

AbstractProductA *ConcreateFactory1::createProductA()
{
    return new ProductA1();
}

AbstractProductB *ConcreateFactory1::createProductB()
{
    return new ProductB1();
}


ConcreateFactory2::ConcreateFactory2()
{

}

ConcreateFactory2::~ConcreateFactory2()
{

}

AbstractProductA *ConcreateFactory2::createProductA()
{
    return new ProductA2();
}

AbstractProductB *ConcreateFactory2::createProductB()
{
    return new ProductB2();
}
