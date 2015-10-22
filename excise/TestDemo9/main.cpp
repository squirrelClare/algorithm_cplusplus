#include <QCoreApplication>
#include<QTextCodec>
#include<QDebug>
#include<QStringList>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    qDebug()<<QObject::tr("以下是编辑字符串操作:")<<endl;
    QString str="hello";
    qDebug()<<QObject::tr("字符串大小为:")<<str.size();

    QString str1="hi\r\n Qt! \n  ";
    qDebug()<<QObject::tr("原字符串为:")<<endl<<str1;
    qDebug()<<QObject::tr("去掉字符串两端的空白:")<<endl<<str1.trimmed();
    qDebug()<<QObject::tr("去掉中间和两端的空白:")<<endl<<str1.simplified();

    QString str2="hi,my,,Qt";
    QStringList list=str2.split(",",QString::SkipEmptyParts);//分割的时候跳过中间空白的部分,即空白部分不存入list.
    qDebug()<<list;


    qDebug()<<QString().isEmpty();
    qDebug()<<QString().isNull();

    qDebug()<<QString("").isEmpty();
    qDebug()<<QString("").isNull();

    QString str3;
    str3="FF";
    bool ok;
    qDebug()<<ok<<(str3);
    int hex=str3.toInt(&ok,16);
    qDebug()<<ok<<hex<<str3;
    qDebug()<<"********************************************************";
    QString name="小明";
    int age=34;
    QString str4=QString("姓名:%1,年龄:%2").arg(name).arg(age);
    qDebug()<<str4;
    qDebug()<<"********************************************************";
    QString str5="%1  %2";
  qDebug()<<str5.arg("%1f","hello");
 qDebug()<<str5.arg("%1f").arg("hello");
    qDebug()<<str5.arg("%2f").arg("hello");
    qDebug()<<str5;
    qDebug()<<"********************************************************";
qreal value=123.456;
qDebug()<<QString("%1").arg(value,0,'f',2);
QString str6=QString("number:%1").arg(value,0,'f',1);
qDebug()<<str6;
qDebug()<<qPrintable(str6);
    return a.exec();
}
