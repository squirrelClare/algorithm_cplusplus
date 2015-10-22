#ifndef STUDENT_H
#define STUDENT_H
#include<QString>
#include<QDebug>
class Student
{
private:
    QString name;
    int age;
    QString number;

public:

    Student(QString name, QString number, int age);
    void Show();
};

#endif // STUDENT_H
