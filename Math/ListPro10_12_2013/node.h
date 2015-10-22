#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node();//构造函数
    //Node(int value);//构造函数，为在链表尾部增加节点做准备
    //Node(int value,Node *p);//构造函数，为在链表中增加节点做准备
    //void SetValue(int value);
    //Node SetNext(Node *next);
    //int GetValue();
    //Node *GetNext();
    int value;
    Node *next;

private:

};

#endif // NODE_H
