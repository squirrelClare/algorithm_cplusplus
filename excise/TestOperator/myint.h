#ifndef MYINT_H
#define MYINT_H
//+,-,*,/
class MyInt
{
public:
    MyInt();
    MyInt(int inValue);

    int GetValue()const;
    void SetValue(const int inValue);
    MyInt& operator =(const MyInt& inMyInt);
    MyInt& operator +(MyInt& inMyInt) const;
protected:
    int value;
};

#endif // MYINT_H

//class Animal{
//    Animal();
//    virtual bool IsAlive(){return true;}//是否活着
//    virtual void Move()=0;//移动方式
//    virtual void Eat()=0;//进食方式
//    virtual void Speak()=0;//说话方式
//    virtual void Sleep()=0;//睡觉方式
//};

//class Dog:public Animal{
//    Dog();
//    bool IsAlive(){return true;}
//    void Move(){cout<<"用四条腿跑";}
//    void Eat(){cout<<"吃骨头";}
//    void Speak(){cout<<"汪汪!!汪星人";}
//    void Sleep(){cout<<"闭着眼睛睡觉,姿势就随便了";}
//};
//class Pig:public Animal{
//    Pig();
//    bool IsAlive(){return true;}
//    void Move(){cout<<"四条腿跑慢慢跑)";}
//    void Eat(){cout<<"有什么吃什么";}
//    void Speak(){cout<<"额,这个不知道怎么模拟";}
//    void Sleep(){cout<<"闭着眼睛睡觉,姿势就随便了";}
//};
//class Bird:public Animal{
//    Bird();
//    bool IsAlive(){return true;}
//    void Move(){cout<<"有翅膀的家伙,飞!!!!!!";}
//    void Eat(){cout<<"小昆虫";}
//    void Speak(){cout<<"喳喳!!!!!";}
//    void Sleep(){cout<<"闭着眼睛睡觉,应该是吧,那个夜猫子就不清楚了";}
//};
//class Fish:public Animal{
//    Fish();
//    void Move(){cout<<"游泳*****";}
//    void Eat(){cout<<"浮游生物!!!";}
//    void Speak(){cout<<"冒泡泡!!!!!";}
//    void Sleep(){cout<<"找个草丛闭着眼睛睡觉!!";}
//};
