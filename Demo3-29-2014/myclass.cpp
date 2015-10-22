#include "myclass.h"

MyClass::MyClass()
{
    ++num;
}

MyClass::~MyClass()
{
    num--;
}

int MyClass::GetNum()
{
    return num;
}
int MyClass::num=0;
