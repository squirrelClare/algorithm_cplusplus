#include "debug.h"
#include<QFileInfo>
#include<QTime>

Debug::Debug(QString fileName)
{
         QFile file(fileName);
    if(!fileName.isEmpty())
    {
           file.open(QIODevice::Append|QIODevice::Text);
    }

    else
    {
        file.open(QIODevice::WriteOnly);
    }
}

Debug::~Debug()
{
}

void Debug::WriteMessage(QString message)
{
  QString str=  QTime::currentTime().toString().append(message).append("#3");
  file->write(str.toStdString().c_str(),strlen(str.toStdString().c_str()));
file->flush();
}

