#ifndef PRODUCT_H
#define PRODUCT_H

class Product
{
public:
    virtual ~Product()=0;
protected:
     Product();
};

class ConcreateProduct:public Product
{
public:
    ~ConcreateProduct();
    ConcreateProduct();

};

#endif // PRODUCT_H
