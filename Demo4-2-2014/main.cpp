#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
typedef struct DNode           //定义双循环链表的数据结构
{
   long key;
   struct DNode *prior,*next;
}DNode;

DNode *del_entry(DNode *L)    //取下指向链表L的第一个元素的指针
{
    DNode *p;
    p=L->next;
    if(p!=L)
    {
        p->prior->next=p->next;
        p->next->prior=p->prior;
    }
    else p=NULL;
    return p;
}

//int power(int x,int y)     //计算以x为底的y次幂
//{   int pro;
//    if(y==0) return 1;
//    if(y>=1)
//       pro=x*power(x,y-1);
//    return pro;
//}

int get_digital(DNode *p,int ii)  //求关键字的第ii位数字
{
    int key1;
    key1=p->key;
    if(ii!=0)
        key1=key1/pow(10,ii);
    return key1%10;
}

void add_entry(DNode *L,DNode *p)
{
    p->prior=L->prior;
    p->next=L;
    L->prior->next=p;
    L->prior=p;
  //  p=L;
}

void append(DNode *L,DNode *L1)     //将一个链表L1连接到链表Ｌ上
{
    if(L1->next!=L1)
    {
        L->prior->next=L1->next;
        L1->next->prior=L->prior;
        L1->prior->next=L;
        L->prior=L1->prior;
    }
}

void radix_sort(DNode *L,int k)             //基数排序函数
{
    DNode *Lhead[10],*p;
    int i,j;
    for(i=0;i<10;i++)
        Lhead[i]=new DNode;
    for(i=0;i<k;i++)
    {   for(j=0;j<10;j++)
                { Lhead[j]->prior=Lhead[j];
                    Lhead[j]->next=Lhead[j];}  //初始化链表
         while(L->next!=L)        //排序
         {
           p=del_entry(L);
           j=get_digital(p,i);
           add_entry(Lhead[j],p);
         }
         for(j=0;j<10;j++)
             append(L,Lhead[j]);
    }
    for(j=0;j<10;j++)
      delete (Lhead[j]);
}

void CreateLink(DNode *L)   //创建链表
{
  DNode *r,*s;
  int flag=1;
  long value;
  r=L;
  while(flag)
  {   cin>>value;
      if(value!=0)
      {
          s=(DNode *)malloc(sizeof(DNode));
          s->key=value;
          r->next=s;
          s->prior=r;
          r=s;
      }
      else
          flag=0;
   }
      L->prior=r;
      r->next=L;
}
//主函数
int main()
{
  DNode *L2=new DNode;
  DNode *q,*h;

  cout<<"enters numbers:";
  CreateLink(L2);
//  for(q=L2->next;q!=L2;q=q->next)
//      cout<<q->key<<endl;

radix_sort(L2,4);//调用排序函数


std::cout<<"排序后的结果为:"<<'\n';
  for(h=L2->next;h!=L2;h=h->next)
      cout<<h->key<<endl;
  return 0;
}
