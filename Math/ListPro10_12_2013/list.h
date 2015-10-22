#include"node.h"
//#define NULL 0
#ifndef LIST_H
#define LIST_H

class List
{
public:
    List();
    List(Node *head);
    bool IsEmport();//判断链表是否为空；
    void ListInsert(int value);//在链表中增加一个节点
    void ListInsert(int value,int i);//把value作为第i个节点的值添加进去
    void ListDelete(int value);//删除链表中的值为value这个节点
    int ListSearch(int value);//查找节点value在链表中的位置
    void ShowOut();//输出链表


private:
    Node *head;

};

#endif // LIST_H
