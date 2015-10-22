#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
    Rectangle();//构造函数
    Rectangle(double side1,double side2);
    void Function();


private:
    double side1;
    double side2;
    double Area(double side1,double side2);
    void  Setsides(double side1,double side2);
    void Setout();
    double Circumference(double side1,double side2);

};

#endif // RECTANGLE_H
