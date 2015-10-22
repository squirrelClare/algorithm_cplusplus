#include <QCoreApplication>
#include<QtNetwork>
#include<QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTcpServer *server=new QTcpServer();
    server->listen(QHostAddress::Any,16000);
    qDebug()<<server->isListening();
    while(server->waitForNewConnection(200000))
    {
    QTcpSocket *socket=server->nextPendingConnection();
    QByteArray qba=socket->readAll();
    qDebug()<<QVariant(qba).toString();
    }
    qDebug()<<"It is over!";
    return a.exec();
}
