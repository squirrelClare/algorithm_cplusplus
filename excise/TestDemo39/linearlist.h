#ifndef LINEARLIST_H
#define LINEARLIST_H
#include<QDebug>
template <typename T> class LinearList
{
public:
     LinearList(int size);//创建一个空的线性表
    ~LinearList();//删除表
    bool IsEmpty();//如果表为空则返回true,否则返回false
    int Length();//返回表的大小(即表中元素的个数)
    bool Find(int index, T &x);//返回表中第index个元素
    int Search(T value);//返回值value在数组中的索引值
    LinearList<T>& Delete(int k,T &x);//删除索引为k的元素,并将它返回至x中
    LinearList<T> &Insert(int k,const T& x);//在索引为k的元素后面插入x
    void OutPut();//输出线性表
    T at(int index);//返回索引值为index的值
    LinearList<T> &add(T value);//往线性表中添加数据
private:
    int length;
    int MaxSize;
    T *element;//一维动态数组
};

template<typename T>
LinearList<T>::LinearList(int size)
{
    MaxSize=size;
    element=new T[MaxSize];
    length=0;
}

template<typename T>
LinearList<T>::~LinearList()
{

}

template<typename T>
bool LinearList<T>::IsEmpty()
{if(length==0)
        return true;
    else
        return false;
}

template<typename T>
int LinearList<T>::Length()
{
    return length;
}

template<typename T>
bool LinearList<T>::Find(int index,T &x)
{
    if(index<0||index>=length)
        return false;
    x=element[index];
    return true;
}

template<typename T>
int LinearList<T>::Search(T value)
{
    for(int i=0;i<length;i++){
        if(element[i]==value)
            return i;
    }
    return -1;//未找到则返回-1
}

template<typename T>
LinearList<T> &LinearList<T>::Delete(int k, T &x)
{
    if(Find(k,x)){
        for(int i=k;i<length-1;i++){
            element[i]=element[i+1];
        }
        length--;
    }
     return *this;
}

template<typename T>
LinearList<T> &LinearList<T>::Insert(int k, const T &x)
{
    if(k<0||k>length){
        qDebug()<<"OutOfbound!";
        return *this;
    }
    if(length==MaxSize){
        qDebug()<<"The memory is not enough!";
        return *this;
    }
    for(int i=length;i>k;i--){
        element[i+1]=element[i];
    }
    element[k]=x;
    length++;
    return *this;

}


template<typename T>
void LinearList<T>::OutPut()
{
    for(int i=0;i<length;i++){
        qDebug()<<element[i];
    }
}


template<typename T>
T LinearList<T>::at(int index)
{
    return element[index];
}

template<typename T>
LinearList<T> &LinearList<T>::add(T value)
{
    if(length>=MaxSize){
        qDebug()<<"OutOfBound";
        return *this;
    }
    element[length]=value;
    length++;
    return *this;
}



#endif // LINEARLIST_H
