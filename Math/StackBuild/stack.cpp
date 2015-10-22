#include "stack.h"
#include<QTextStream>

Stack::Stack(int p[],int size)
{//传入数组p[]由指针变量*p接收,size为p[]的大小

    /*不使用sizeof(p)/sizeof(int)的原因是:p[]传入的只是数组的首地址值
       this->p获取的只是这个首地址值,*p指向数组p[].但是并没有把p[]复制过来*/

    this->p=p;
    this->top=size-1;//top为栈顶,是以栈顶所在数组位置的索引值为标识的
}

void Stack::show()
{//输出栈内部的全部数据
    QTextStream out(stdout);
    for(int i=0;i<=top;++i){
        out<<p[i]<<" ";
        out.flush();//刷出缓存区的全部数据
    }
    out<<endl;//输出完后换行
}

void Stack::Push(int value)
{//压栈操作
    ++top;
    p[top]=value;
}

int Stack::Pop()
{//出栈操作(弹出一个数据),并返回出栈的数据
    --top;
    return p[top+1];
}

bool Stack::IsEmpty()
{//判断栈是否为空.
    if(top==-1)
        return true;
    else
        return false;
}
