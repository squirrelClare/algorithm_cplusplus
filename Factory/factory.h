#ifndef FACTORY_H
#define FACTORY_H
class Product;
class Factory
{
public:
    virtual ~Factory()=0;
    virtual Product* createProduct()=0;
    Factory();
};

class ConcreateFactory:public Factory
{
public:
    ~ConcreateFactory();
    ConcreateFactory();
    Product* createProduct();
};

#endif // FACTORY_H
