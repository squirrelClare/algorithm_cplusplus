#include "tree.h"

#include<QTextStream>

QTextStream out(stdout);

Tree::Tree()
{
    m_pRoot=__null;
}

void Tree::InOrderWalk(Node *p)
{
    if (p!=__null){
        InOrderWalk(p->GetLeft());
        out<<p->GetKey()<<" ";
        out.flush();
        InOrderWalk(p->GetRight());
    }
}

void Tree::PreorderWalk(Node *p)
{
    if (p!=__null){
        out<<p->GetKey()<<" ";
        out.flush();
        PreorderWalk(p->GetLeft());
        PreorderWalk(p->GetRight());
    }
}

void Tree::PostorderWalk(Node *p)
{
    if(p!=__null){
        PreorderWalk(p->GetLeft());
        PreorderWalk(p->GetRight());
        out<<p->GetKey()<<" ";
        out.flush();
    }
}

void Tree::Append(int value)
{
    Node *pNew=new Node(value);
    Node *pX=this->m_pRoot;
    Node *pY=__null;

    //查询插入值应该在树种的位置
    while (pX!=__null){
        pY=pX;
        if (pX->GetKey()<value){
            pX=pX->GetRight();
        }else{
            pX=pX->GetLeft();
        }
    }

    //设置新节点的双亲,左孩子,右孩子
    pNew->SetParent(pY);

    if (pY==__null){
        this->m_pRoot=pNew;
    }else if (value<pY->GetKey()){
        pY->SetLeft(pNew);
    }else{
        pY->SetRight(pNew);
    }
}

Node *Tree::Search(Node *pStart,int value)
{
    //利用二叉搜索树的性质查找
    if (pStart==__null||pStart->GetKey()==value){
        return pStart;
    }
    if (value<pStart->GetKey()){
        return Search(pStart->GetLeft(),value);
    }else{
        return Search(pStart->GetRight(),value);
    }
}

Node *Tree::SearchFromRoot(int value)
{
    //从根节点开始查找
    return Search(m_pRoot,value);
}

Node *Tree::IterativeSearch(Node *pStart, int value)
{
    while (pStart!=__null||pStart->GetKey()!=value){
        if (pStart->GetKey()<value){
            pStart=pStart->GetLeft();
        }else{
            pStart=pStart->GetRight();
        }
    }
    return pStart;
}

Node *Tree::IterativeSearchFromRoot(int value)
{
    return IterativeSearch(m_pRoot,value);
}

bool Tree::IsEmpty()
{
    if (m_pRoot==__null)
        return true;
    else
        return false;
}

Node *Tree::Max(Node *p)
{
    //最右叶子节点即为最大值的节点
    while (p->GetRight()!=__null){
        p=p->GetRight();
    }
    return p;
}

Node *Tree::Min(Node *p)
{
    //最左叶子节点即为最小值的节点
    while (p->GetLeft()!=__null){
        p=p->GetLeft();
    }
    return p;
}

Node *Tree::MaxFromRoot()
{
    return Max(m_pRoot);
}

Node *Tree::MinFromRoot()
{
    return Min(m_pRoot);
}

Node *Tree::Successor(Node *p)
{
    if (p->GetRight()!=__null){
        return Min(p->GetRight());
    }

    Node *pTemp=p->GetParent();
    while (pTemp!=__null&&pTemp->GetRight()==p){
        p=pTemp;
        pTemp=pTemp->GetParent();
    }
    return pTemp;
}

Node *Tree::Predecessor(Node *p)
{
    if (p->GetLeft()!=__null){
        return Max(p->GetLeft());
    }

    Node *pTemp=p->GetParent();
    while(pTemp!=__null&&pTemp->GetLeft()==p){
        p=pTemp;
        pTemp=pTemp->GetParent();
    }
    return pTemp;
}

void Tree::DeleteNode(Node *p)
{
    /**
    1.p无左孩子
    2.p无右孩子
    3.p有左孩子和右孩子*/
    if (p->GetLeft()==__null){//1
        Transplant(p,p->GetRight());
    }else if (p->GetRight()==__null){//2
        Transplant(p,p->GetLeft());
    }else{Node *p_1=Min(p->GetRight());//3
        if (p_1->GetParent()!=p){
            Transplant(p_1,p_1->GetRight());
            p_1->SetRight(p->GetRight());
            p_1->GetRight()->SetParent(p_1);
        }
        Transplant(p,p_1);
        p_1->SetLeft(p->GetLeft());
        p_1->GetLeft()->SetParent(p_1);
    }
    delete p;
}

void Tree::Show()
{   out<<"inoder walk:"<<endl;
    InOrderWalk(m_pRoot);
    out<<endl;

    out<<"preoder walk:"<<endl;
    PreorderWalk(m_pRoot);
    out<<endl;

    out<<"postoder walk:"<<endl;
    PostorderWalk(m_pRoot);
    out<<endl;
}

void Tree::Transplant(Node *u, Node *v)
{
    if (u->GetParent()==__null){//u为根节点
        m_pRoot=v;
    }else if (u==u->GetParent()->GetLeft()){//u为其父节点的左孩子
        u->GetParent()->SetLeft(v);
    }else{//u为其父节点的右孩子
        u->GetParent()->SetRight(v);
    }
    if (v!=__null){//如果v不为空则设置其父节点为u.parent
        v->SetParent(u->GetParent());
    }
    delete u;
}
