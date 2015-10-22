#ifndef ABSTRACTIONIMP_H
#define ABSTRACTIONIMP_H

class AbstractionImp
{
public:
    virtual ~AbstractionImp();
    virtual void operation()=0;
protected:
    AbstractionImp();
};

class ConcreateAbstractionImpA:public AbstractionImp
{
public:
    ConcreateAbstractionImpA();
    ~ConcreateAbstractionImpA();
    virtual void operation();
};

class ConcreateAbstractionImpB:public AbstractionImp
{
public:
    ConcreateAbstractionImpB();
    ~ConcreateAbstractionImpB();
    virtual void operation();
};
#endif // ABSTRACTIONIMP_H
