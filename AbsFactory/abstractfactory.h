#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
class AbstractProductA;
class AbstractProductB;
class AbstractFactory
{
public:
    virtual ~AbstractFactory();
    virtual AbstractProductA* createProductA()=0;
    virtual AbstractProductB* createProductB()=0;
protected:
    AbstractFactory();
};
class ConcreateFactory1:public AbstractFactory
{
public:
    ConcreateFactory1();
    ~ConcreateFactory1();
    AbstractProductA* createProductA();
    AbstractProductB* createProductB();
};

class ConcreateFactory2:public AbstractFactory
{
public:
    ConcreateFactory2();
    ~ConcreateFactory2();
    AbstractProductA* createProductA();
    AbstractProductB* createProductB();
};
#endif // ABSTRACTFACTORY_H
