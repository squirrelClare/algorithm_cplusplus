#ifndef DEBUG_H
#define DEBUG_H
#include<QString>
#include<QFile>


class Debug
{
public:
    Debug(QString fileName);
    ~Debug();
QFile *file;

    void WriteMessage(QString message);
};
#endif // DEBUG_H
