#include "student.h"

Student::Student(QString name, QString number, int age)
{
    this->name=name;
    this->age=age;
    this->number=number;
}

void Student::Show()
{
    qDebug()<<"����:"<<this->name<<" "<<"ѧ��:"<<this->number<<" "<<"����:"<<this->age;
}
