#include "grate.h"

Grate::Grate(QString grateName)
{

this->grateName=grateName;
}

void Grate::Add(Student stu)
{
       className.append(stu);
}
void Grate::ShowGrate()
{
    qDebug()<<"*********************************************";
    QList<Student>::iterator i=className.begin();
    while(i!=className.end())
    {
        qDebug()<<"Äê¼¶:"<<this->grateName;
    (*i).Show();
    i++;
    }
}

