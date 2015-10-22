#ifndef CLASS_H
#define CLASS_H
#include<student.h>
#include<QDebug>
#include<QList>
#include<QString>
class Grate
{
private:
 QString grateName;
 QList<Student> className;
 public:
     Grate(QString grateName);//创建一个学生
    void Add(Student stu);
    void ShowGrate();//输出班级名称.
};

#endif // CLASS_H
