#include <QCoreApplication>
#include<QDebug>
#include<QFile>
#include<QFileInfo>
#include<QTextCodec>
#include<QObject>
#include<QDateTime>
#include<QTextStream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QString path1="C:/Users/lenovo/Desktop/json.zip";
    QFile file;
    file.setFileName(path1);
    qDebug()<<QObject::tr("文件是否存在:")<<file.exists();
    qDebug()<<QObject::tr("文件大小:")<<file.size()<<endl;
    QFileInfo fileinfor(path1);
    qDebug()<<QObject::tr("文件路径:")<<fileinfor.path();
    qDebug()<<QObject::tr("文件名:")<<fileinfor.fileName();
    qDebug()<<QObject::tr("文件后缀:")<<fileinfor.suffix()<<endl
           <<QObject::tr("文件创建时间:")<<fileinfor.created().toString()<<endl
          <<QObject::tr("文件最后一次打开时间:")<<fileinfor.lastRead().toString();

    QFile file1("‪C:/Users/lenovo/Desktop/code.txt");
    qDebug()<< file1.open(QIODevice::ReadWrite|QIODevice::Text);
    //if(!file1.open(QIODevice::ReadWrite|QIODevice::Text))
    //    return 0;
    //QTextStream out(&file1);
    //QString array1=out.readAll();

    //qDebug()<<array1.isEmpty()<<array1.length();
    //qDebug()<<QObject::tr("文件内容:")<<array1;
    qDebug()<<file1.readAll();
    file1.close();
    //qDebug()<<QObject::tr("文件内容:")<<array1;//QString::number(array.toDouble());
     return a.exec();
}
