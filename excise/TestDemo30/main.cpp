#include <QCoreApplication>
#include<QDebug>
#include<QDomDocument>
#include<QFile>
#include<QTextCodec>
#include<QDir>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    QFile file("D:/Program Files/QT/build-TestDemo28-桌面-Debug/test.xml");
    if(!file.open(QIODevice::ReadOnly))
        return 0;
    else qDebug()<<"Success!";
    QDomDocument doc;
    QByteArray bty= file.readAll();
    if(!doc.setContent(bty))
        return 0;
    else qDebug()<<"Success!";
    QDomNode child=doc.firstChild();
    qDebug()<<child.nodeName()<<child.nodeValue();
    QDomElement element=doc.documentElement();
    QDomElement element1=element.firstChildElement();
    QDomNodeList list=element1.childNodes();
    for(int i=0;i<list.count()-1;i++)
    {
        if(list.at(i).isElement())
        qDebug()<< list.at(i).toElement().tagName()<<list.at(i).toElement().text();
    }

    file.close();

qDebug()<<QDir::currentPath();
    return a.exec();
}
