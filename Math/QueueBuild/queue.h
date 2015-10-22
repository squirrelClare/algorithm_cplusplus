#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
public:
    Queue(int p[], int size, int head, int tail);
    void Show();
    void EnQueue(int value);
    int DeQueue();
private:
    int *q;
    int head,tail;
    int size;
};

#endif // QUEUE_H
