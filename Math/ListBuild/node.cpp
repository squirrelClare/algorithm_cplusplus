#include "node.h"

#define NULL 0

Node::Node()
{//构造一个空的节点
}

Node::Node(int value)
{//构造函数
    this->value=value;
    this->next=NULL;
}

Node::Node(int value, Node *p)
{//构造函数
    this->value=value;
    this->next=p;
}

void Node::SetValue(int value)
{//设置节点的值
    this->value=value;
}

void Node::SetNext(Node *next)
{//设置该节点指向的下一个节点
    this->next=next;
}

int Node::GetValue()
{//返回节点的值
    return value;
}

Node *Node::GetNext()
{//返回该节点所指向的下一个节点
    return next;
}
