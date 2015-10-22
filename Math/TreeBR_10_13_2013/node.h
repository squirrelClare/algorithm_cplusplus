#ifndef NODE_H
#define NODE_H
/**
    1.构造函数
    2.设置双亲
    3.设置左孩子
    4.设置右孩子
    5.设置节点的关键字
    6.获取节点的关键字
    7.获取节点的双亲
    8.获取节点的左孩子
    9.获取节点的右孩子
    10.判断节点是否为空
    11.设置节点颜色
    12.获取节点颜色*/

enum COLOR{red,black};//red=0,black==1;
class Node
{
public:
    Node();
    Node(int key);
    void SetLeft(Node *left);
    void SetRight(Node *right);
    void SetParent(Node *parent);
    void SetKey(int key);
    int GetKey();
    Node *GetParent();
    Node *GetLeft();
    Node *GetRight();
    bool IsEmpty();
    void SetToRed();
    void SetToBlack();
    COLOR GetColor();
private:
    Node *parent;
    Node *left;
    Node *right;
    int key;
    COLOR color;

};

#endif // NODE_H
