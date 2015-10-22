#include <QCoreApplication>
#include<QtNetwork>
#include<QDebug>
#include<QFile>
#include<QDataStream>
#include<QTextCodec>
QString GetContent(QString url){
    QNetworkAccessManager manager;
    QEventLoop loop;
       //发出请求
       QNetworkReply *reply = manager.get(QNetworkRequest(QUrl(url)));
       //请求结束并下载完成后，退出子事件循环
       QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
       //开启子事件循环
    loop.exec();
    QString code = reply->readAll();
    return code;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    QString url="http://bbs.csdn.net/forums/Qt/recommend";
    QString str=GetContent(url);
    QFile file("C:/Users/lenovo/Desktop/Downlo.txt");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out<<str;
    return a.exec();
}


