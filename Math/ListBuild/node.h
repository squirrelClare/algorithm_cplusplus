#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node();
    Node(int value);
    Node(int value, Node *p);
    void SetValue(int value);
    void SetNext(Node *next);
    int GetValue();
    Node *GetNext();

private:
    int value;
    Node *next;
};

#endif // NODE_H
