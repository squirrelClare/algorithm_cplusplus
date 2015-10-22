#include <QCoreApplication>
#include"producer.h"
#include"consumer.h"
#include<QSemaphore>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    int DataSize = 10;
    int BufferSize = 5;
    char *buffer=new char(BufferSize);
    QSemaphore* freeBytes=new QSemaphore(BufferSize);
    QSemaphore* usedBytes=new QSemaphore();

    Producer *producer=new Producer(freeBytes,usedBytes,buffer);
    Consumer *consumer=new Consumer(freeBytes,usedBytes,buffer);
    producer->start();
    consumer->start();
    producer->wait();
    consumer->wait();
    return a.exec();
}
