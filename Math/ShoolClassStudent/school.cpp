#include "school.h"

School::School(QString schoolName)
{
    this->schoolName=schoolName;
}

void School::Add(QString grateName, Grate grate)
{
   school.insert(grateName,grate);
}

void School::ShowMemeber()
{
    QMap<QString,Grate>::iterator it=school.begin();
    while(it!=school.end())
    {
        qDebug()<<"Äê¼¶"<<it.key();
        it.value().ShowGrate();
        it++;
    }
}
