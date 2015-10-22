#include <QCoreApplication>
#include<QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> list;
   list<<1<<24<<25<<12<<25<<4<<635<<123<<56<<12;
   qDebug()<<list;
   for(int j=0;j<list.length();j++)
   {
       int key=list.at(j);
       int i=j-1;
       while (i>-1&&list.at(i)<key)
       {
            list.replace(i+1,list.at(i));
            i--;
       }
        list.replace(i+1,key);
   }
   qDebug()<<list;
    return a.exec();
}
