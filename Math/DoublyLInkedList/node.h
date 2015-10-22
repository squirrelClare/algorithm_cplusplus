#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node();
    Node(int value);
    Node(int value, Node *prev, Node *next);

    void SetValue(int value);
    void SetPrevi(Node *p);
    void SetNext(Node *p);
    int GetValue();
    Node *GetNext();
    Node *GetPrevi();

private:
    int value;
    Node *previous;
    Node *next;
};

#endif // NODE_H
