#ifndef DATAWRITEREAD_H
#define DATAWRITEREAD_H
#include<QString>
#include<QFile>
#include<QTextStream>
#include<QObject>
#include<QDebug>
class DataWriteRead
{private:
    QString fileName;
    QString obj;
public:
    DataWriteRead(QString str);
  void  DataWrite(QString obj);
  void DataRead();
};

#endif // DATAWRITEREAD_H
