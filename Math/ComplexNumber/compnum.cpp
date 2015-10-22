#include "compnum.h"
#include<QDebug>

CompNum::CompNum():real(0),image(0)//只有构造函数才能用这种初始化的方式
{
}

CompNum::CompNum(int inReal, int inImage):real(inReal),image(inImage)//只有构造函数才能用这种初始化的方式
{
}

CompNum::CompNum(CompNum &rhs):real(rhs.GetReal()),image(rhs.GetImage())//只有构造函数才能用这种初始化的方式
{
}

CompNum::CompNum(CompNum &&rhs)
{
    this->real=rhs.GetReal();
    this->image=rhs.GetImage();
    this->temp=rhs.temp;
    rhs.temp=__null;
}

CompNum::~CompNum()
{
    real=0;
    image=9;
}

int CompNum::GetReal() const
{
    return real;
}

int CompNum::GetImage() const
{
    return image;
}

void CompNum::SetReal(int inReal=0)//只有构造函数才能用这种初始化的方式
{
    real=inReal;
}

void CompNum::SetImage(int inImage=0)
{
    image=inImage;// image(inImage);这种方式是初始化的时候才能用的，在这个函数中，
    //image已经初始化过了，所以不能再初始化
}

void CompNum::Show() const
{
    qDebug()<<real<<"+"<<image<<"i";
}

CompNum &CompNum::operator =(const CompNum &inCompNum)
{//const CompNum &inCompNum :const作用是使得inCompNum不能被改变，&作用是对inCompNum进行引用而不是对inCompNum进行操作
    this->SetImage(inCompNum.GetImage());
    this->SetReal(inCompNum.GetReal());
    return *this;
}

CompNum &CompNum::operator +=(const CompNum &inCompNum)
{
    this->real+=inCompNum.GetReal();
    this->image+=inCompNum.GetImage();
    return *this;
}

CompNum &CompNum::operator +(CompNum &inCompNum) const//const放在函数的结尾表示该函数不能做任何改变值得操作。
{
    CompNum newComp;
    newComp.SetReal(this->GetReal()+inCompNum.GetReal());
    newComp.SetImage(this->GetImage()+inCompNum.GetImage());
    return newComp;
}

CompNum &CompNum::operator -=(const CompNum &inCompNum)
{

}

CompNum &CompNum::operator -(CompNum &inCompNum) const
{

}

CompNum &CompNum::operator *=(const CompNum &inCompNum)
{

}

CompNum &CompNum::operator *(CompNum &inCompNum) const
{

}

CompNum &CompNum::operator /=(const CompNum &inCompNum)
{

}

CompNum &CompNum::operator /(CompNum &inCompNum) const
{

}



