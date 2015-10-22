#ifndef CONSUMER_H
#define CONSUMER_H

#include <QThread>
#include<QSemaphore>
#include<QDebug>

class Consumer : public QThread
{
public:
    Consumer(QSemaphore* freeBytes, QSemaphore* usedBytes, char *buffer);
    QSemaphore *freeBytes;
    QSemaphore *usedBytes;
private:

    int DataSize;
    int BufferSize;
    char *buffer;
    void run();
};

#endif // CONSUMER_H
