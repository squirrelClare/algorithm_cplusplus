#ifndef CATCHER_H
#define CATCHER_H
#include<QString>
#include<QVector>
#include<QFile>
#include<QTextStream>
#include<stdexcept>
#include<exception>
#include"fileopenerror.h"
#include<iostream>
#include"myexception.h"
/**目的:测试和熟悉C++的异常处理
 *
逻辑错误都继承自logic_error
domain_error
 域错误
invalid_argument
 非法参数
length_error
 通常是创建对象是给出的尺寸太大
out_of_range
 访问超界

运行时错误都继承自runtime_error
异常
 描述
overflow_error
 上溢
range_error
 超出表示范围
underflow_error
 下溢
    */
class Catcher
{
public:
    Catcher();
    virtual ~Catcher();

    virtual void ReadIntegerFile(const QString& fileName, QVector<QString> &dest);
    virtual auto SafeDivide(const int num, int const den)->int ;
    virtual void DoSomething() const;
};
#endif // CATCHER_H
