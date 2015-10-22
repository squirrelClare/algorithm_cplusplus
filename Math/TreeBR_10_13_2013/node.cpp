#include "node.h"

Node::Node()
{//构造函数
    parent=__null;
    left=__null;
    right=__null;
    key=__null;
    color=red;
}

Node::Node(int key)
{//构造函数
    this->key=key;
    parent=__null;
    left=__null;
    right=__null;
    color=red;
}

void Node::SetLeft(Node *left)
{//设置左孩子
    this->left=left;
}

void Node::SetRight(Node *right)
{//设置右孩子
    this->right=right;
}

void Node::SetParent(Node *parent)
{//设置双亲
    this->parent=parent;
}

void Node::SetKey(int key)
{//设置关键字
    this->key=key;
}


int Node::GetKey()
{//获取关键字
    return key;
}

Node *Node::GetParent()
{//获取双亲
    return parent;
}

Node *Node::GetLeft()
{//获取左孩子
    return left;
}

Node *Node::GetRight()
{//获取右孩子
    return right;
}

bool Node::IsEmpty()
{
    if(key==__null){
        return true;
    }
    return false;
}

void Node::SetToRed()
{
    this->color=red;
}

void Node::SetToBlack()
{
    this->color=black;
}

COLOR Node::GetColor()
{
    return this->color;
}
