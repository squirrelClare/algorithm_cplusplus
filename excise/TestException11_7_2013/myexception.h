#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include<exception>
#include<iostream>
/**
 *描述:自定义一个嵌套型异常
 */
class MyException:public std::exception,public std::nested_exception
{
public:
    MyException(const char* msg);
    virtual ~MyException();
    virtual const char* what() const throw(){
        return mMsg.c_str();
    }
protected:
    std::string mMsg;
};

#endif // MYEXCEPTION_H
