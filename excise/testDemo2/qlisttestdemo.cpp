#include "qlisttestdemo.h"

QListTestDemo::QListTestDemo()
{
}

void QListTestDemo::Testprepend()
{
    QList<QString> list;
     list.prepend("one");
     qDebug()<<list.count()<<endl<<list;
     list.prepend("two");
      qDebug()<<list.count()<<endl<<list;
     list.prepend("three");
      qDebug()<<list.count()<<endl<<list;

}

void QListTestDemo::Testpush_back()
{
    QList<QString> list;
     list.push_back("one");
     qDebug()<<list.count()<<endl<<list;
     list.push_back("two");
      qDebug()<<list.count()<<endl<<list;
     list.push_back("three");
      qDebug()<<list.count()<<endl<<list;

}

void QListTestDemo::Testpush_front()
{
    QList<QString> list;
     list.push_front("one");
     qDebug()<<list.count()<<endl<<list;
     list.push_front("two");
      qDebug()<<list.count()<<endl<<list;
     list.push_front("three");
      qDebug()<<list.count()<<endl<<list;

}

void QListTestDemo::TesttoSet()
{
    QStringList list;
     list << "Julia" << "Mike" << "Mike" << "Julia" << "Julia";

     QSet<QString> set = list.toSet();
     qDebug()<<set.contains("Julia");  // returns true
     qDebug()<<set.contains("Mike");   // returns true
     qDebug()<<set.size();
     qDebug()<<set;// returns 2
}

void QListTestDemo::Testremoveall()
{
    QList<QString> list;
     list << "sun" << "cloud" << "sun" << "rain";
     qDebug()<<list;
     list.removeAll("sun");
     qDebug()<<list;
}

void QListTestDemo::Testvalue()
{
    QList<QString> list;
     list << "sun" << "cloud" << "sun" << "rain";
     qDebug()<<list;
    qDebug()<<list.value(2,"sdaew");//如果index超过了list的边界那么会返回后面定义的一个值.
    qDebug()<<list;
}

void QListTestDemo::Testopertor1()
{
    QList<QString> list;
     list << "sun" << "cloud" << "sun" << "rain";
     QList<QString> list1;
      list1 << "sun1" << "cloud1" << "sun1" << "rain1";

      qDebug()<<list.operator !=(list1)<<list.operator ==(list1);
     QList<QString> list2=list.operator =(list);
     qDebug()<<list2;

     qDebug()<<list.operator +(list1);
     qDebug()<<list;

     qDebug()<<list.operator +=(list1);
     qDebug()<<list;
}

void QListTestDemo::Testopertor2()
{
    QList<QString> list;
     list << "sun" << "cloud" << "sun" << "rain";
     QList<QString> list1;
      list1 << "sun1" << "cloud1" << "sun1" << "rain1";
      list +=list1;
      qDebug()<<list.at(4);

}
