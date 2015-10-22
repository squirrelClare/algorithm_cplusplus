#include "mainwindow.h"
#include <QApplication>
#include<QDebug>
#include<QtSql>
#include<QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
     QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
      QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE","connection1");
      db.setDatabaseName("my1.db");
    if(!db.open())
    {
        qDebug()<<"NO_db";
        return 0;
    }
    QSqlQuery query(db);
    query.exec("create table type(id varchar primary key, name varchar)");
    query.exec(QString("insert into type values('0', '请选择类型')"));
    query.exec(QString("insert into type values('01', '电视')"));
    query.exec(QString("insert into type values('02', '空调')"));

    // 创建品牌表
    query.exec("create table brand(id varchar primary key, name varchar, "
               "type varchar, price int, sum int, sell int, last int)");
    query.exec(QString("insert into brand values('01', '海信', '电视', 3699, 50, 10, 40)"));
    query.exec(QString("insert into brand values('02', '创维', '电视', 3499, 20, 5, 15)"));
    query.exec(QString("insert into brand values('03', '海尔', '电视', 4199, 80, 40, 40)"));
    query.exec(QString("insert into brand values('04', '王牌', '电视', 3999, 40, 10, 30)"));
    query.exec(QString("insert into brand values('05', '海尔', '空调', 2899, 60, 10, 50)"));
    query.exec(QString("insert into brand values('06', '格力', '空调', 2799, 70, 20, 50)"));

//    QSqlDatabase db1=QSqlDatabase::database("connection1");

//    if(db1.open())
//{
//        qDebug()<<"NO_db1!";
//        return 0;
//    }
//    QSqlQuery query(db1);
    query.exec(QString("select * from brand"));
            while(query.next())
            {
                qDebug() << query.value(0).toInt() << query.value(1).toString()<<query.value(2).toString()<<query.value(3).toInt()<<query.value(4).toInt()<<query.value(5).toInt();
            };
//   qDebug()<<query.value(2).toString();
    MainWindow w;
    w.show();
    
    return a.exec();
}
