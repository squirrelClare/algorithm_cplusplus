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
     Grate(QString grateName);//����һ��ѧ��
    void Add(Student stu);
    void ShowGrate();//����༶����.
};

#endif // CLASS_H
