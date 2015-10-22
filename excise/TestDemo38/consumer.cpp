#include "consumer.h"

Consumer::Consumer(QSemaphore* freeBytes,QSemaphore* usedBytes,char* buffer)
{
    DataSize = 10;
    BufferSize = 5;
//    buffer=new char(BufferSize);
    this->buffer=buffer;
    this->freeBytes=freeBytes;
    this->usedBytes=usedBytes;

//    freeBytes=new QSemaphore(BufferSize);
//    usedBytes=new QSemaphore();
}


void Consumer::run()
{
    for (int i = 0; i < DataSize; ++i) {
            usedBytes->acquire();
            qDebug() << QString("consumer: %1").arg(buffer[i % BufferSize])<<"  "<<i % BufferSize;
            freeBytes->release();
    }
}
