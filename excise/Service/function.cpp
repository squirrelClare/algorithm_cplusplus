#include "function.h"

Function::Function()
{
}

QString Function::ExtractWebFileName(QString src)
{
    QString result;
    for(int i=src.length()-1;i>=0;--i )
    {
        if(src.at(i)=='/')
           {
            result=src.right(src.length()-1- i);
        break;
        }
    }
    return result;
}
