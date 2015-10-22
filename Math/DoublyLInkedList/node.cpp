#include "node.h"
#define NULL 0;

Node::Node()
{
    previous=NULL;
    next=NULL;
}

Node::Node(int value)
{
    this->value=value;
    previous=NULL;
    next=NULL;
}

Node::Node(int value, Node *prev,Node *next)
{
    this->value=value;
    this->next=next;
    this->previous=prev;
}

void Node::SetValue(int value)
{
    this->value=value;
}

void Node::SetPrevi(Node *p)
{
    this->previous=p;
}

void Node::SetNext(Node *p)
{
    this->next=p;
}

int Node::GetValue()
{
    return value;
}

Node *Node::GetNext()
{
    return next;
}

Node *Node::GetPrevi()
{
    return previous;
}
