#ifndef TREE_H
#define TREE_H

#include"node.h"

class Tree
{
public:
    Tree();//构造函数
    void InOrderWalk(Node *p);//中序遍历
    void PreorderWalk(Node  *p);//前序遍历
    void PostorderWalk(Node *p);//后续遍历
    void Append(int value);//添加值
    Node *Search(Node *pStart, int value);//从指定节点查找(递归查找)
    Node *SearchFromRoot(int value);//查找
    Node *IterativeSearch(Node *pStart, int value);//从指定节点查找(迭代查找)
    Node *IterativeSearchFromRoot(int value);//查找
    bool IsEmpty();//判断树是否为空
    Node *Max(Node *p);//返回以p为根节点子树的最大值节点
    Node *Min(Node *p);//返回以p为根节点子树的最小值节点
    Node *MaxFromRoot();//返回树的最大值节点
    Node *MinFromRoot();//返回树的最小值节点
    Node *Successor(Node *p);//返回指定节点的后继
    Node *Predecessor(Node *p);//返回指定节点的前驱
    void DeleteNode(Node *p);//删除指定节点
    void Show();//输出当前树

    Node *m_pRoot;//树的根节点
private:
    void Transplant(Node *u,Node *v);//用以v为根节点的子树替换以u为根节点的子树
};

#endif // TREE_H
