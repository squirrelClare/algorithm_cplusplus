#include <QCoreApplication>
#include<QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> list;
   list<<1<<24<<25<<12<<25<<4<<635<<123<<56<<12;
   qDebug()<<list;
   for(int j=1;j<list.length();j++)
   {
       int i=0;
       int key=list.at(j);
       int count=0;
       while(i<j&&count<1)//count是为判断其是否发现一个值是比key小的，只需要发现一个就可以了。
       {

           if(list.at(i)<key)//如果发现一个值比要插入的值Key小那么自它以后的值都往右挪一位。
         {
               for(int h=j;h>i+1;h--)
           {
               list.replace(h,list.at(h-1));
           }
           list.replace(i,key);
           count++;
           }
           i++;
       }
   }
   qDebug()<<list;
    return a.exec();
}
