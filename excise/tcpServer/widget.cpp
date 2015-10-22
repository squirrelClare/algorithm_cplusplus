#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    tcpServer=new QTcpServer(this);
    if(!tcpServer->listen(QHostAddress::LocalHost,6666))
    {//监听本机的6666端口，如果出错就输出错误信息并关闭
        qDebug()<<tcpServer->errorString();
        close();

    }
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(sendMessage()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::sendMessage()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<(quint16)0;
    out<<tr("hello Tcp!!!");
    out.device()->seek(0);
    out<<(quint16)(block.size()-sizeof(quint16));
    QTcpSocket *clientConnection=tcpServer->nextPendingConnection();
    //我们获取已经建立的连接的子套接字。
    connect(clientConnection,SIGNAL(disconnected()),clientConnection,SLOT(deleteLater()));
            clientConnection->write(block);
    clientConnection->disconnectFromHost();
    ui->statusLabel->setText("send message successful!!!");
    //发送数据成功后，显示提示
}
