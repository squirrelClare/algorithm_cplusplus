#include <iostream>
#include"factory.h"
#include"product.h"
using namespace std;

int main()
{
   Factory* fac=new ConcreateFactory();
   Product* p=fac->createProduct();
    return 0;
}

