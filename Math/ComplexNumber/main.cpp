#include <QCoreApplication>
#include"compnum.h"
#include<QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CompNum num1(1,3),num2(4,6);//CompNum *num1=new CompNum(1,3);
    CompNum num3=num1+num2;

    num1.Show();
    num2.Show();
    num3.Show();
    qDebug()<<"*****************************";

    CompNum num1Copy(num1);//这一行和CompNum num1Copy=num1;的作用是一样的。
                                                    // 调用的都是CompNum(CompNum &rhs);
    //CompNum *num1Copy=new CompNum(num1);
    //CompNum::CompNum(CompNum &rhs):real(rhs.GetReal()),image(rhs.GetImage())//只有构造函数才能用这种初始化的方式
    //{
    //}

    /*
    CompNum &rhs=num1;
    num1Copy.real=rhs.real;
    num1Copy.image=rhs.image;
    */

    num1Copy+=num2;//这两行说明操作没有对num1进行改变。

    num1.Show();
    num2.Show();
    num1Copy.Show();
    qDebug()<<"*****************************";

    CompNum num1Copy2;
    num1Copy2=num1;//这样和上述的效果是一样的，但是调用的是CompNum& operator=(const CompNum &inCompNum);
//    num1Copy2.operator =(num1);
    num1Copy2+=num2;//同样也没有对num1进行改变
//    2+3=5;
    int  value1=4,value2=78,value3=67;
    value1=value2+value3;
    value1+=value2;
//    num1Copy2.operator +=(num2);
    num1.Show();
    num2.Show();
    num1Copy2.Show();

    CompNum* num4=new CompNum(23,34);
    CompNum*& num5=num4;//指针引用
    num5->SetImage(3343);
    num4->Show();
    num1+=*num4;
    num1.Show();
    return a.exec();
}
