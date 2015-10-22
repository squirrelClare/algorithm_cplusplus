#include "list.h"
#include<QTextStream>

List::List()
{
    head=NULL;
}

List::List(int value)
{
    head=new Node(value);
}

void List::AddAtEnd(int value)
{//向链表中插入数值
    Node *p=head;
    if(head==NULL){//如果链表为空
        head=new Node(value);//此时head->next=NULL
    }else{
        //如果链表不为空,则一步步遍历到链表的结尾
        while(p->GetNext()!=NULL){
            p=p->GetNext();
        }

        //把value插入链表中,新的结尾由new Node(value)的next完成指向
        p->SetNext(new Node(value));
    }
}

void List::AddAtEnd(Node *p)
{//向链表中插入节点
    Node *point=head;

    if(head==NULL){
        head=p;
    }else{
        while(point->GetNext()!=NULL){
            point=point->GetNext();
        }
        point->SetNext(p);
    }
}

void List::ShowAll()
{//输出链表中的数据
    QTextStream out(stdout);
    Node *p=head;
    if(head==NULL){
        out<<"The list is empty!"<<endl;
    }else{
        while(p->GetNext()!=NULL){
            out<<p->GetValue()<<'\t';
            out.flush();
            p=p->GetNext();
        }
        out<<p->GetValue()<<endl;
    }
}

void List::AddBefore(int index, int value)
{
    Node *p=new Node(value);
    Node *point=head;
    int flag=0;

    //如果链表为空
    if(head==NULL){
        head=p;
        return;
    }

    //如果在链表头部插入
    if(index==0){
        p->SetNext(head);
        head=p;
        return;
    }

    //如果要在index=1前插入
    if(index==1){
        Node *p_1=head->GetNext();
        p->SetNext(p_1);
        head->SetNext(p);
        return;
    }

    //如果index>=2
    /*采取此种做法的原因在于,此链表是单向链表.只能调用SetNext()设置下一个指针
    .因此必须获取要目标指针的前一个指针,而获取该指针必须利用目标指针的前面的第二个指针
    之后用point=point->GetNext();获取目标指针的前一个指针*/
    while(flag<=index-2){
        point=point->GetNext();
        ++flag;
    }
    Node *point_1=point->GetNext();
    point->SetNext(p);
    p->SetNext(point_1);
}
