#include <QCoreApplication>
#include<QDebug>
#include<QStringList>
#include<QDateTime>
#include<QString>
#include<QTextCodec>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
  QString string = "QQ#34241988;Email#songwei_163@163.com;Address#Chengdu,Sichuan;MSN#songwei_163@163.com;Home Page#http://www.google.com";//定义一个字符串
      QStringList strlist=string.split(";");//将字符串以“；”为界分割成数组形式存到QStringList变量strlist中
      qDebug()<<strlist;
      QStringList list=strlist.at(1).split("#");//将strlist中的第一号元素以“#”隔开并存入list中
      qDebug()<<list.at(0);//打印出list中的首个元素
      qDebug()<<"*********************************";
      QDateTime dt;
      QTime time;
      QDate data;
      dt.setTime(time.currentTime());
      dt.setDate(data.currentDate());
      QString currentDate = dt.toString("yyyy:MM:dd:hh:mm:ss");
      qDebug()<<currentDate;
      QStringList list1;
      list1<<"fafae"<<"refdfg"<<"fwr"<<"fqqefw"<<"1df3";
      qDebug()<<list1;
      list1.takeLast();
      qDebug()<<list1;
      QString str="fjqhqiehqieh";
       qDebug()<<str;

        str.remove(str.length()-1,1);
       qDebug()<<str;
       QString str4;
          QString str5;
       str4="dadqweqeq %1,%2";
      str5= str4.arg("Hello Word").arg("HI Qt");
       qDebug()<<str4;
       qDebug()<<str5;



//        str5.arg("%1f", "Hello");        // returns "%1f Hello"
//        //str5.arg("%1f").arg("Hello");    // returns "Hellof %2"
//        qDebug()<<str5;
    return a.exec();
}
