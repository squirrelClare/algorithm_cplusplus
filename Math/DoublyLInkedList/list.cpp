#include "list.h"
#include<QTextStream>

QTextStream out(stdout);

List::List()
{//初始化
    head=NULL;
    tail=NULL;
    size=0;
}

void List::Append(int value)
{//在链表的结尾添加新的值
    Node *p=new Node(value);
    //如果链表为空
    if(IsEmpty()){
        head=p;
        tail=p;
        ++size;
        return;
    }
    //如果链表不为空
    p->SetPrevi(tail);
    tail->SetNext(p);
    tail=p;
    ++size;
}

int List::Delete(int index)
{//删除指定位置的值
    int flag=0;
    Node *p=head;

    while(p->GetNext()!=NULL&&flag!=index){
        p=p->GetNext();
        ++flag;
    }
    //删除节点
    Node *prev_p=p->GetPrevi();
    Node *next_p=p->GetNext();
    prev_p->SetNext(next_p);
    next_p->SetPrevi(prev_p);
    --size;
    //返回的删除的节点的值
    return p->GetValue();
}


int List::ListLength()
{//链表的大小
    return size;
}

bool List::IsEmpty()
{//链表是否为空
    if(size!=0)return false;
    return true;
}

int List::IndexOf(int value)
{//查找指定值在链表中的位置
    Node *p=head;
    int index=0;
    while(p->GetNext()!=NULL&&p->GetValue()!=value){
        p=p->GetNext();
        ++index;
    }
    //返回索引值
    return index;
}


void List::Show()
{//输出链表
    //如果链表为空
    if(this->IsEmpty()){
        out<<"the list is empty!";
        return;
    }

    //链表非空
    Node *p=head;
    while(p->GetNext()!=NULL){
        out<<p->GetValue()<<" ";
        out.flush();
        p=p->GetNext();
    }
    out<<p->GetValue()<<endl;
}
