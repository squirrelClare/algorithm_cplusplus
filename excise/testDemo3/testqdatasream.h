#ifndef TESTQDATASREAM_H
#define TESTQDATASREAM_H
#include<QFile>
#include<QDataStream>
#include<QDebug>
class TestQDataSream
{
public:
    TestQDataSream();
    static void testOut();
    static void testIn();
    static void others();
};

#endif // TESTQDATASREAM_H
