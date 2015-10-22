#include <QCoreApplication>
#include"stack.h"
#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //初始化数组
    int p[]={21,14,14,2,5,35,34,36,3,6,36,3};
    int size=sizeof(p)/sizeof(int);

    //实例化一个栈
    Stack *s=new Stack(p,size);

    //输出当前栈内元素
    s->show();

    //判断栈是否为空
    qDebug()<<s->IsEmpty();

    //出栈操作
    s->Pop();
    s->Pop();
    s->Pop();
    s->Pop();

    //输出出栈操作后的栈内元素
    s->show();

    //压栈操作
    s->Push(56);
    s->Push(42);
    
    //输出压栈后的栈内元素
    s->show();

    return a.exec();
}
