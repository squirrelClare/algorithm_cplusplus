#ifndef QLISTDEMO_H
#define QLISTDEMO_H
#include<QString>
#include<QList>
#include<QDebug>
class QListDemo
{
    private:
QList<QString> list;
public:

    QListDemo();
    void QStringMove(int index_1, int index_2);
  void Add(QString s);//增加.
    void Clear();//清除列表.
  void SetChar(int index,QString s);//改变元素.
     void DeleteItem(int index);//删除元素.
    void ShowMemeber();//单个输出列表.
    void ShowList();//整体输出列表.
     QString GetChar(int index);
     void Sort();//排序.
};

#endif // QLISTDEMO_H
