#ifndef ABSTRACTION_H
#define ABSTRACTION_H

class AbstractionImp;
class Abstraction
{
public:
    virtual ~Abstraction();
    virtual void operation()=0;
protected:
    Abstraction();
};

class RefinedAbstraction:public Abstraction
{
public:
    RefinedAbstraction(AbstractionImp* imp);
    ~RefinedAbstraction();
    void operation();
private:
    AbstractionImp* _imp;
};

#endif // ABSTRACTIONIMP_H
