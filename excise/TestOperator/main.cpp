#include <QCoreApplication>
#include"myint.h"
#include<QDebug>
#include<exception>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyInt value1(56),value2(131),value3(13);
    value3=value1+value2;
    qDebug()<<value3.GetValue();
    return a.exec();
}
//double Max(const double valueLeft,const double valueRight){
//    return valueLeft>valueRight?valueLeft:valueRight;
//}

//double Max(double const valueLeft,double const valueRight){
//    return valueLeft>valueRight?valueLeft:valueRight;
//}
//class A{
//public:
//    A();
//    ......
//    double Max(double valueLeft,double valueRight) const;
//    ........
//protected:
//    int valueOfA;
//};
