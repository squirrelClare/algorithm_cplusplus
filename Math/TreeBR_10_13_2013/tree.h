#ifndef TREE_H
#define TREE_H

#include"node.h"

class Tree
{
public:
    Tree();
    Tree(Node *p);

    Node *head;
    Node *NIL;
    void Append(int value);
    void InOrderWalk(Node *p);//中序遍历
    void PreorderWalk(Node  *p);//前序遍历
    void PostorderWalk(Node *p);//后续遍历
    void Show();//输出当前树
    void Delete(int value);
private:
    void LeftRotate(Node *p);
    void RightRotate(Node *p);
    void RBInsertFixup(Node *p);
    void Transplant(Node *u,Node *v);
    void RBDeleteFixup(Node *p);
    Node *GetNode(int value);
    Node *GetMin(Node *p);
};

#endif // TREE_H
