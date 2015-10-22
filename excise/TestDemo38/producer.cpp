#include "producer.h"
#include<QTime>

Producer::Producer(QSemaphore* freeBytes,QSemaphore* usedBytes,char* buffer)
{
    DataSize = 10;
    BufferSize = 5;
//    buffer=new char(BufferSize);

//    freeBytes=new QSemaphore(BufferSize);
//    usedBytes=new QSemaphore();
    this->buffer=buffer;
    this->freeBytes=freeBytes;
    this->usedBytes=usedBytes;

}


void Producer::run()
{

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for (int i = 0; i < DataSize; ++i) {
        freeBytes->acquire();
        buffer[i % BufferSize] = "ACGT"[(int)qrand() % 4];
        qDebug() << QString("producer: %1").arg(buffer[i % BufferSize])<<"  "<<i % BufferSize;
        usedBytes->release();
    }
}
