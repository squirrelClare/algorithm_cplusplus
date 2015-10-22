#ifndef QLISTTESTDEMO_H
#define QLISTTESTDEMO_H
#include<QDebug>
#include<QList>
#include<QSet>
#include<QStringList>
class QListTestDemo
{
public:
    QListTestDemo();
    static void Testprepend();
    static void Testpush_back();
    static void Testpush_front();
    static void TesttoSet();
    static void Testremoveall();
    static void Testvalue();
    static void Testopertor1();//!=
    static void Testopertor2();

};

#endif // QLISTTESTDEMO_H
