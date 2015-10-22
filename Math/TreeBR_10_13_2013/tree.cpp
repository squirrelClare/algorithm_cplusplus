#include "tree.h"
#include<QTextStream>

QTextStream out(stdout);

Tree::Tree()
{//构造函数
    //此时树为空,即只有节点NIL.树的head也就是NIL.无需设置parent,left,right.
    NIL=new Node();
    NIL->SetToBlack();
    head=NIL;
}

Tree::Tree(Node *p)
{//构造函数
    // 以传入的节点p作为树的head,所以需要设置parent,left,right.
    head=p;
    NIL=new Node();
    NIL->SetToBlack();
    head->SetParent(NIL);
    head->SetLeft(NIL);
    head->SetRight(NIL);
}

void Tree::Append(int value)
{
    Node *pNew=new Node(value);
    Node *y=NIL;
    Node *x=head;

    //寻找新节点的插入位置
    while (x!=NIL){
        y=x;
        if (value<x->GetKey()){
            x=x->GetLeft();
        }else{
            x=x->GetRight();
        }
    }
    pNew->SetParent(y);

    //判断新节点的类型
    if (y==NIL){
        head=pNew;
    }else if (value<y->GetKey()){
        y->SetLeft(pNew);
    }else{
        y->SetRight(pNew);
    }
    //对新插入的节点做处理,下几行也可以放在函数的开始部分
    pNew->SetRight(NIL);
    pNew->SetLeft(NIL);
    pNew->SetToRed();//可以不要这一句,因为节点的初始颜色就是红色

    RBInsertFixup(pNew);
}

void Tree::LeftRotate(Node *p)
{//左旋
    Node *trans=p->GetRight();
    p->SetRight(trans->GetLeft());
    if (trans->GetLeft()!=NIL){
        trans->GetLeft()->SetParent(p);
    }
    trans->SetParent(p->GetParent());
    if (p->GetParent()==NIL){
        head=trans;
    }else if (p->GetParent()->GetLeft()==p){
        p->GetParent()->SetLeft(trans);
    }else{
        p->GetParent()->SetRight(trans);
    }
    trans->SetLeft(p);
    p->SetParent(trans);
}

void Tree::RightRotate(Node *p)
{//右旋
    Node *trans=p->GetLeft();
    p->SetLeft(trans->GetRight());
    if (trans->GetRight()!=NIL){
        trans->GetRight()->SetParent(p);
    }
    trans->SetParent(p->GetParent());
    if (p->GetParent()==NIL){
        head=trans;
    }else if (p->GetParent()->GetLeft()==p){
        p->GetParent()->SetLeft(trans);
    }else{
        p->GetParent()->SetRight(trans);
    }
    trans->SetRight(p);
    p->SetParent(trans);
}

void Tree::RBInsertFixup(Node *p)
{//插入节点后保持红黑树的性质
    while (p->GetParent()->GetColor()==red){
        if(p->GetParent()==p->GetParent()->GetParent()->GetLeft()){
            Node *y=p->GetParent()->GetParent()->GetRight();
            if(y->GetColor()==red){
                p->GetParent()->SetToBlack();
                y->SetToBlack();
                p->GetParent()->GetParent()->SetToRed();
                p=p->GetParent()->GetParent();
            }else{
                if (p==p->GetParent()->GetRight()){
                    p=p->GetParent();
                    LeftRotate(p);
                }
                p->GetParent()->SetToBlack();
                p->GetParent()->GetParent()->SetToRed();
                RightRotate(p->GetParent()->GetParent());
            }
        }else{
            Node *y=p->GetParent()->GetParent()->GetLeft();
            if(y->GetColor()==red){
                p->GetParent()->SetToBlack();
                y->SetToBlack();
                p->GetParent()->GetParent()->SetToRed();
                p=p->GetParent()->GetParent();
            }else{
                if(p==p->GetParent()->GetLeft()){
                    p=p->GetParent();
                    RightRotate(p);
                }
                p->GetParent()->SetToBlack();
                p->GetParent()->GetParent()->SetToRed();
                LeftRotate(p->GetParent()->GetParent());
            }
        }
    }
    head->SetToBlack();
}

void Tree::Transplant(Node *u, Node *v)
{//以v为根的子树替代以u为根的子树
    if (u->GetParent()==NIL){
        this->head=v;
    }
    else if (u==u->GetParent()->GetLeft()){
        u->GetParent()->SetLeft(v);
    }else{
        u->GetParent()->SetRight(v);
    }

    v->SetParent(u->GetParent());
}

void Tree::RBDeleteFixup(Node *p)
{//删除一个节点后保持红黑树的性质,目前还没有理解
}

void Tree::InOrderWalk(Node *p)
{
    if (p!=NIL){
        InOrderWalk(p->GetLeft());
        out<<p->GetKey()<<" ";
        out.flush();
        InOrderWalk(p->GetRight());
    }
}

void Tree::PreorderWalk(Node *p)
{
    if (p!=NIL){
        out<<p->GetKey()<<" ";
        out.flush();
        PreorderWalk(p->GetLeft());
        PreorderWalk(p->GetRight());
    }
}

void Tree::PostorderWalk(Node *p)
{
    if(p!=NIL){
        PreorderWalk(p->GetLeft());
        PreorderWalk(p->GetRight());
        out<<p->GetKey()<<" ";
        out.flush();
    }
}

void Tree::Show()
{   out<<"inoder walk:"<<endl;
    InOrderWalk(head);
    out<<endl;

    out<<"preoder walk:"<<endl;
    PreorderWalk(head);
    out<<endl;

    out<<"postoder walk:"<<endl;
    PostorderWalk(head);
    out<<endl;

    out<<"***************************"<<endl;
}

void Tree::Delete(int value)
{
    Node *z=GetNode(value);//获取value对应的节点
    Node *y=z;
    Node *x;
    COLOR yOriginalColor=y->GetColor();//存储节点的颜色

    if (z->GetLeft()==NIL){//情况1
        x=z->GetRight();
        Transplant(z,z->GetRight());
    }else if (z->GetRight()==NIL){//情况2
        x=z->GetLeft();
        Transplant(z,z->GetLeft());
    }else{//情况3:含有两个子节点
        y=GetMin(z->GetRight());
        yOriginalColor=y->GetColor();
        x=y->GetRight();

        if (y->GetParent()==z){
            x->SetParent(y);
        }else{
            Transplant(y,y->GetRight());
            y->SetRight(z->GetRight());
            y->GetRight()->SetParent(y);
        }

        Transplant(z,y);
        y->SetLeft(z->GetLeft());
        y->GetLeft()->SetParent(y);
        if (z->GetColor()==red){
            y->SetToRed();
        }else{
            y->SetToBlack();
        }
    }

//    if (yOriginalColor==black){
//        RBDeleteFixup(x);
//    }
}


Node *Tree::GetNode(int value)
{//返回关键字为value的节点
    Node *p=head;
    while (p->GetKey()!=value&&p!=NIL){
        if (value<p->GetKey()){
            p=p->GetLeft();
        }else{
            p=p->GetRight();
        }
    }
    return p;
}

Node *Tree::GetMin(Node *p)
{
    Node *min=p;
    while (p->GetLeft()!=NIL){
        p=p->GetLeft();
    }
    return min;
}
