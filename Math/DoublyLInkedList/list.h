#ifndef LIST_H
#define LIST_H
#include"node.h"
class List
{
public:
    List();
    void Append(int value);
    int Delete(int index);
    void Show();
    int ListLength();
    bool IsEmpty();
    int IndexOf(int value);
private:
    Node *head;
    Node *tail;
    int size;
};

#endif // LIST_H
