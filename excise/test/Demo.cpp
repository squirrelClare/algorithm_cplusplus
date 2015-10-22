#include<Demo.h>
void Demo::Demo2( )
{
    QList<QString> ql;

    ql.append("zhangsan1");
    ql.append("zhangsan2");

    ql.append("zhangsan3");

    ql.append("zhangsan4");

    ql.append("zhangsan5");

    for(int i=0;i<ql.length();i++)
    {
        qDebug()<<ql.at(i);

    }

}

void Demo::Demo3()
{
    QList<QString> list;
    list.append("January");
    list.append("February");
    list.append("December");

    QList<QString>::iterator i;
    for (i = list.begin(); i != list.end(); ++i)
        qDebug() << *i << endl;
}

void Demo::Demo4()
{

    std::list<double> stdlist;
    stdlist.push_back(1.2);
    stdlist.push_back(0.5);
    stdlist.push_back(3.14);

    qDebug()<<"stdlist is:";
    qDebug()<< stdlist.front()<< endl;
    qDebug()<<"******************************************************************";

    QList<double> list = QList<double>::fromStdList(stdlist);
    qDebug()<<"list is:";
    qDebug() << list<< endl;
    qDebug()<<"******************************************************************";

    qDebug()<<"sort list is:";
    qSort(list);
    qDebug() << list<< endl;
    qDebug()<<"******************************************************************";

}

void Demo::Demo5()
{
    QVector<int> vector(200,12);
    qDebug()<<vector;
    qDebug()<<"******************************************************************";
}

void Demo::ListIndexofDemo5()
{
    QList<QString> list;
    QList<int> index_list;
     list << "A" << "B" << "C" << "B" << "A";
    index_list.append( list.indexOf("B"));          // returns 1
     index_list.append(list.indexOf("B", 1));       // returns 1
     index_list.append(list.indexOf("B", 2));       // returns 3
     index_list.append(list.indexOf("X"));          // returns -1
     qDebug()<<"list:";
     qDebug()<<"B"<<"B"<<"B"<<"X";
     qDebug()<<"index_list:";
     qDebug()<<index_list<<endl;
     qDebug()<<"******************************************************************";
}

void Demo::ListInsert()
{
    QList<QString> list;
     list << "alpha" << "beta" << "delta";
     qDebug()<<"before insert:"<<endl<<list<<endl;
     list.insert(2, "gamma");
     qDebug()<<"insert:"<<endl<<list<<endl<<list.isEmpty()<<endl<<list.back()<<endl;
     QList<QString>::Iterator it=list.end();
     qDebug()<<*it;
     while(it!=list.end())
     {
   qDebug()<<*it;
   it++;
     }
     list.clear();
     qDebug()<<list.isEmpty();
      qDebug()<<"******************************************************************";
}

Demo::Demo()
{
}

void Demo::Demo1()
{

    QSet<int> set;
    set << 20 << 30 << 40  << 70<<12<<1<<23<<1;

    QList<int> list = QList<int>::fromSet(set);
    qSort(list);
    for(int i=0;list.length();i++)
    {
        qDebug()<<list.at(i);
   }
    qDebug()<<"******************************************************************";

}

