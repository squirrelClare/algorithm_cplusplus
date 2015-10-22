#include "queue.h"
#include<QTextStream>

QTextStream in(stdin);
QTextStream out(stdout);

Queue::Queue(int p[],int size,int head,int tail)
{//初始化,int *q接收int p[],size为数组大小,head队头,tail队尾
    this->q=p;
    this->size=size;
    this->head=head;
    this->tail=tail;
}

void Queue::Show()
{//输出当前队列

    out<<"The current queue is:"<<endl;

    if(tail>=head)//队头在队尾前面
        for(int i=head;i<tail;++i){
            out<<q[i]<<" ";
            out.flush();
        }
    else{//队头在队尾后面

        //后半部分队列输出
        for(int i=head;i<size;++i){
            out<<q[i]<<" ";
            out.flush();
        }

        //前半部分队列输出
        for(int i=0;i<tail;++i){
            out<<q[i]<<" ";
            out.flush();
        }
    }
    out<<endl;
}

void Queue::EnQueue(int value)
{//往队列中插入元素

    //检查队列是否向上溢出
    if(head==tail+1){
        out<<"Up overflow"<<endl;
        return;
    }

    //操作队尾
    q[tail]=value;

    if(tail+1==size)
        tail=0;
    else
        ++tail;
}

int Queue::DeQueue()
{//删除队头元素

    //检查队列是否向下溢出
    if(head==tail){
        out<<"Down overflow"<<endl;
        return NULL;
    }

    //操作队头
    int outValue=q[head];
    if(head+1==size)
        head=0;
    else
        ++head;
    return outValue;
}
