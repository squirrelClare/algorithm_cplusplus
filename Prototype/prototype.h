#ifndef PROTOTYPE_H
#define PROTOTYPE_H

class Prototype
{
public:
    virtual ~Prototype();
    virtual Prototype* clone() const =0;
protected:
    Prototype();
};

class ConcreatePrototype:public Prototype
{
public:
    ConcreatePrototype();
    ConcreatePrototype(ConcreatePrototype const * cp);
    ~ConcreatePrototype();

    Prototype* clone()const;
};

#endif // PROTOTYPE_H
