#include "list.h"
#include<QTextStream>

List::List()
{
    head=__null;
}

List::List(Node *head)
{
    this->head=head;
}

bool List::IsEmport()//判断链表是否为空
{
    if(head==__null)
        return true;
    return false;
}

void List::ListInsert(int value)//在链表的尾部增加节点
{
//    Node *point=new Node();
//    Node *move=new Node();
//    point=head;
//    move=head;

    Node *move=head;
    Node *point=new Node();

    if(IsEmport()){
        head=new Node();
        head->value=value;
        }
    else{
        while(move->next!=__null){
            move=move->next;
        }

        move->next=point;
        point->value=value;
    }
}

void List::ListInsert(int value, int i)
{
    int j;
    Node *head=new Node();
    Node *point=new Node();
    Node *move=new Node();
    point=head;
    while (j<i-1&&point->next) {
        point=point->next;
    }
    if(j==i-1){

        move->value=value;
        point->next=move;
        move->next=point->next;

    }
    else {
        ListInsert(value);
    }
}

void List::ListDelete(int value)
{
    QTextStream out(stdout);
    Node *head=new Node();
    Node *p=new Node();
    Node *q=new Node();
    p=head;
    while(p->value!=value&&p->next){
        q=p;
        p=p->next;
    }
    if(p->value==value)
        q->next=p->next;
    else out<<"can not find.";
    out.flush();
}

void List::ShowOut()
{
    QTextStream out(stdout);

//    head=new Node();
    Node *p=head;

    if(head==__null){
        out<<"The list is empty!"<<endl;
    }else{
    while(p->next!=__null){
        out<<p->value<<" ";
        out.flush();
        p=p->next;
    }
    out<<p->value<<" ";
    out.flush();
    }
}
