#ifndef SCHOOL_H
#define SCHOOL_H
#include<QString>
#include<student.h>
#include<QMap>
#include<grate.h>
#include<QDebug>
class School
{
private:
    QString schoolName;
    QMap<QString,Grate> school;
public:
    School(QString schoolName);
    void Add(QString grateName, Grate grate);
    void ShowMemeber();
};

#endif // SCHOOL_H
