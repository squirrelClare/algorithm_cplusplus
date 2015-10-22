#include <QCoreApplication>
#include<QtNetwork>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTcpSocket *sendSocket=new QTcpSocket();
    sendSocket->connectToHost("59.41.32.24",16000);
    QString str="hellow  tcp!";
    sendSocket->write(str.toStdString().c_str(),strlen(str.toStdString().c_str()));
    return a.exec();
}
