#include "rectangle.h"
#include<iostream>
#include<QDebug>

using namespace std;

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(double side1, double side2)
{
    this->side1=side1;
    this->side2=side2;
}

void Rectangle::Function()
{
    Setsides(side1,side2);
    Area(side1,side2);
    Circumference(side1,side2);
    Setout();

}


double Rectangle::Area(double side1, double side2)//求长方形的面积
{
    this->side1=side1;
    this->side2=side2;
    return side1*side2;

}

void Rectangle::Setsides(double side1, double side2)//设置长和宽
{
    this->side1=side1;
    this->side2=side2;

    qDebug()<<"Please input two sides of rectangle :";
    cin>>side1>>side2;
}

void Rectangle::Setout()//输出
{
    qDebug()<<"此长方形的面积、周长分别是："<<endl;
}


double Rectangle::Circumference(double side1, double side2)//求长方形的周长
{
    this->side1=side1;
    this->side2=side2;
    return 2.0*(side1+side2);
}
