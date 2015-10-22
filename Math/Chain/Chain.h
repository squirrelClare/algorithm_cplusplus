#ifndef CHAIN_H
#define CHAIN_H

template<class T>
class ChainNode{
    friend Chain<T>;
private:
    T data;
    ChainNode<T> *link;
};
template<class T>
class Chain{
public:
    Chain(){
        first=0;
    }
    ~Chain();
    bool IsEmpty() const{return first==0;}
    int Length() const;
    bool Find(int k,T &x) const;
    int Search(const T &x) const;
    Chain<T> &Delete(int k,T &x);
    Chain<T> &Insert(int k,const T &x);
    void OutPut() const;
private:
    ChainNode<T> *first;
};

template<class T>
Chain<T>::~Chain()
{
    ChainNode<T> *next;
    while(first){
        next=first->link;
        delete first;
        first=next;
    }
}

#endif // CHAIN_H
