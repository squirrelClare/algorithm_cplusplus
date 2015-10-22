#ifndef DEMO_H
#define DEMO_H
#include<QString>

class Demo
{
private:
    QString name;
    int age;
    QString addr;
    static  int max;

public:
    Demo(QString name,int age,QString addr);
    ~Demo();
    void Show();
};

#endif // DEMO_H
