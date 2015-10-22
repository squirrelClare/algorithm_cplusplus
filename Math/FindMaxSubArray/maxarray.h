#ifndef MAXARRAY_H
#define MAXARRAY_H
#include<QString>
#include<QList>
#include<result.h>
#include<QFile>
#include<QStringList>
class MaxArray
{
public:
    MaxArray();
    ~MaxArray();
    Result MaxArrayReturn(QList<double>listInput);
    Result FindLeft(int low, int high, QList<double> listInput);//寻找左侧最大子数组.
    Result FindRight(int low,int high,QList<double> listInput);//寻找右侧最大子数组.
    Result FindCross(int low,int mid,int high,QList<double> listInput);//寻找跨越中点最大子数组.
    QList<double> InputData(QString path);//从文件中读取股票走势.
};


#endif // MAXARRAY_H
