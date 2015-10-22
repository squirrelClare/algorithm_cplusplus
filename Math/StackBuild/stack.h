#ifndef STACK_H
#define STACK_H

class Stack
{
public:
    Stack(int p[],int size);
    void show();
    void Push(int value);
    int Pop();
    bool IsEmpty();
private:
    int top;
    int *p;
};

#endif // STACK_H
