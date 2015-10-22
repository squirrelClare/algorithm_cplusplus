#ifndef MYCLASS_H
#define MYCLASS_H
#include<string>
#include<iostream>
class MyClass
{
public:
    //三个都是构造函数,参数类型不同,也就是构造函数重载
    MyClass();
    MyClass(std::string str);
    MyClass(char* s);

};

#endif // MYCLASS_H
