#include "myclass.h"

MyClass::MyClass()
{
}

MyClass::MyClass(std::string str)
{
    //一旦此构造函数被调用,将有以下输出
    std::cout<<"using \" string \" and the anser is :"<<str<<std::endl;
}

MyClass::MyClass(char *s)
{
    //一旦此构造函数被调用,将有以下输出
    std::cout<<"using \" char* \" and the anser is :"<<s<<std::endl;
}
