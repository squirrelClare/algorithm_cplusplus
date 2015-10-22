#include "datawriteread.h"

DataWriteRead::DataWriteRead(QString str)
{
    fileName=str;
     qDebug()<<"The fileName is:"<<str;
}

void DataWriteRead::DataWrite(QString obj)
{
    QFile file(fileName);
    if(file.open(QIODevice::Append|QIODevice::Text))
       {QTextStream out(&file);
    out<<obj<<"\n";
    }
}

void DataWriteRead::DataRead()
{
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
       {QTextStream in(&file);
        QString line;
        while(!in.atEnd())
        {
            line=in.readLine();
                    qDebug()<<line;
        }
    }

}
