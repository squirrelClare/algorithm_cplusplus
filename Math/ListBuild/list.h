#ifndef LIST_H
#define LIST_H

#include"node.h"
class List
{
public:
    List();
    List(int value);
    void AddAtEnd(int value);
    void AddAtEnd(Node *p);
    void ShowAll();
    void AddBefore(int index, int value);
    void DeleteValue(int value);
private:
    Node *head;
};

#endif // LIST_H
