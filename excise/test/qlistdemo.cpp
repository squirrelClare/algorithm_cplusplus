#include "qlistdemo.h"

QListDemo::QListDemo()
{
}

void QListDemo::QStringMove(int index_1,int index_2)
{
    this->list.move(index_1,index_2);
}

void QListDemo::Add(QString s)
{
    this->list.append(s);

}

void QListDemo::Clear()
{
    this->list.clear();
}

void QListDemo::SetChar(int index, QString s)
{
    this->list.replace(index,s);
}

void QListDemo::DeleteItem(int index)
{
    this->list.removeAt(index);
}


void QListDemo::ShowMemeber()
{
    QList<QString>::iterator i=this->list.begin();
    while(i!=this->list.end())
    {
        qDebug()<<*i;
        i++;
    }

}

void QListDemo::ShowList()
{
    qDebug()<<this->list;
}

QString QListDemo::GetChar(int index)
{
    return this->list.at(index);
}

void QListDemo::Sort()
{
    qSort(this->list);
}
