#include "node.h"
//#define NULL 0
Node::Node()
{//构造一个空节点
    value=__null;
    next=__null;
}
/*Node::Node(int value){
    this->value=value;
    next=NULL;
}

Node::Node(int value, Node *next)//构造函数,为在中间增加节点做准备
{
    this->value=value;
    this->next=next;
}

void Node::SetValue(int value)//对构造的空函数设置值
{
    this->value=value;
}

Node Node::SetNext(Node *next)//对构造的空函数设置指向下一个节点的指针
{
    this->next=next;
}

int Node::GetValue()
{
    return value;
}

Node Node::GetNext()
{
    return *next;

}*/
