#include "student.h"

Student::Student(QString name, QString number, int age)
{
    this->name=name;
    this->age=age;
    this->number=number;
}

void Student::Show()
{
    qDebug()<<"ĞÕÃû:"<<this->name<<" "<<"Ñ§ºÅ:"<<this->number<<" "<<"ÄêÁä:"<<this->age;
}
