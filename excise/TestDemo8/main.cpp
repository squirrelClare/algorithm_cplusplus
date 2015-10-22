#include <QCoreApplication>
#include<QTextCodec>
#include<QDebug>
#include<QStringList>
#include<QVector>
#include<QtGlobal>
#include<QDateTime>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
     QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
     QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));
     QStringList list;
     list<<"one"<<"two"<<"three";
     qDebug()<<QObject::tr("qCopu() methord:");
     QVector<QString>vect(3);
     qCopy(list.begin(),list.end(),vect.begin());
     qDebug()<<vect;
     /****************************************************************************************************/
     qDebug()<<endl<<QObject::tr("qEqual() methord:");
     bool bl=qEqual(list.begin(),list.end(),vect.begin());
             qDebug()<<bl;
//             QList<QString>::iterator i;
//             i=qFind(list.begin,list.end(),"two");
 /****************************************************************************************************/
             qDebug()<<endl<<QObject::tr("qFind() methord:");
              QStringList::const_iterator i= qFind(list.begin(), list.end(), "two");
             qDebug()<<*i;
  /****************************************************************************************************/
      qDebug()<<endl<<QObject::tr("qFill() methord:");
      qFill(list.begin(),list.end(),"eleven");
      qDebug()<<list;
 /****************************************************************************************************/
      QList<int>list2;
      list2<<2<<31<<13<<2<<2<<2<<134<<2<<123<<4<<5<<3<<5<<51;
      qDebug()<<endl<<QObject::tr("qCount() methord:");
      int number=0;
      qCount(list2.begin(),list2.end(),2,number);
      qDebug()<<"The number of 2 is:"<<number;
      qSort(list2);
      QList<int>::iterator j=qLowerBound(list2.begin(),list2.end(),22);
     list2.insert(j,22);
     /****************************************************************************************************/
     qDebug()<<list2;
     qStableSort(list2);
qDebug()<<endl<<list2;
/****************************************************************************************************/
qSort(list2.begin(),list2.end(),qGreater<int>());
qDebug()<<endl<<list2;
/****************************************************************************************************/
qStableSort(list2.begin(),list2.end(),qGreater<int>());
qDebug()<<endl<<list2;
/****************************************************************************************************/
double d1=311.3998;
double d2=0.231314;
qDebug()<<endl<<"before swap:"<<d1<<" "<<d2;
qSwap(d1,d2);
qDebug()<<"then swap:"<<d1<<" "<<d2;
/****************************************************************************************************/
int int_a=qBound(2,49,12);
qDebug()<<"int_a="<<int_a;

    QDateTime time = QDateTime::currentDateTime();
    //QString s=time.toString("yyyy-MM-dd hh:mm:ss");
    qDebug()<<time.toString();
        return a.exec();

}
