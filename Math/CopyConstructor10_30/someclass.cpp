#include "someclass.h"

SomeClass::SomeClass()
{
    this->mString="";
    this->mValue=0;
}

SomeClass::SomeClass(QString inString, int inValue)
{
    this->mString=inString;
    this->mValue=inValue;
}

//复制构造函数
SomeClass::SomeClass(const SomeClass &src):mValue(src.mValue),mString(src.mString)
{
}

QString SomeClass::GetString() const
{
    return mString;
}

int SomeClass::GetValue() const
{
    return mValue;
}

SomeClass &SomeClass::SetString(const QString &inString)
{
    this->mString=inString;
    return *this;
}

SomeClass &SomeClass::SetValue(const int &inValue)
{
    this->mValue=inValue;
    return *this;
}

//"="运算符重载
SomeClass &SomeClass::operator =(const SomeClass &src)
{
    this->mString=src.mString;
    this->mValue=src.mValue;
    return *this;
}

//"+="运算符重载
SomeClass &SomeClass::operator +=(const SomeClass &src)
{
    this->mString+=src.mString;
    this->mValue+=src.mValue;
}
