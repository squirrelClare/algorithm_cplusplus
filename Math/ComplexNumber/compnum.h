#ifndef COMPNUM_H
#define COMPNUM_H

//复数：real为实部，image为虚部
class CompNum
{//这些对象都不是new的
public:
    CompNum();
    CompNum(int inReal,int inImage);
    CompNum(CompNum &rhs);//复制构造函数，即新建一个和rhs完全一样的复数，但不是rhs本身
    CompNum(CompNum&& rhs);//移动复制构造函数
    virtual ~CompNum();
    virtual int GetReal()const;//获取实部
    virtual int GetImage()const;//获取虚部
    virtual void SetReal(int inReal);
    virtual void SetImage(int inImage);
    virtual void Show()const;

    virtual CompNum& operator=(const CompNum &inCompNum);
    virtual CompNum& operator +=(const CompNum &inCompNum);
    virtual CompNum& operator +(CompNum &inCompNum)const;

    //下面几种数学运算，仿照上述三个自己重载试试
    virtual CompNum& operator -=(const CompNum &inCompNum);
    virtual CompNum& operator -(CompNum &inCompNum)const;
    virtual CompNum& operator *=(const CompNum &inCompNum);
    virtual CompNum& operator *(CompNum &inCompNum)const;
    virtual CompNum& operator /=(const CompNum &inCompNum);
    virtual CompNum& operator /(CompNum &inCompNum)const;

    int* temp;

private:
    int real;
    int image;

};

#endif // COMPNUM_H
