#ifndef PRODUCER_H
#define PRODUCER_H

#include <QThread>
#include<QSemaphore>
#include<QDebug>

class Producer : public QThread
{
public:
    Producer(QSemaphore *freeBytes, QSemaphore *usedBytes, char *buffer);
    QSemaphore *freeBytes;
    QSemaphore *usedBytes;
private:

    int DataSize;
    int BufferSize;
    char *buffer;
    void run();
};

#endif // PRODUCER_H
