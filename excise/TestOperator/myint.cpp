#include "myint.h"

MyInt::MyInt():value(0)
{
}

MyInt::MyInt(int inValue)
{
    value=inValue;
}

int MyInt::GetValue() const
{
    return value;
}

void MyInt::SetValue(const int inValue)
{
    this->value=inValue;
}

//MyInt v,v1;int a,b;
//a=b;
//v=v1;

MyInt &MyInt::operator =(const MyInt &inMyInt)
{
    this->value=inMyInt.GetValue()*100;
    return *this;
}

MyInt &MyInt::operator +(MyInt &inMyInt) const//c=a+b;*this+inMyInt
{
    MyInt *newInt=new MyInt();
    newInt->SetValue( this->value-inMyInt.GetValue());
    return *newInt;
}
