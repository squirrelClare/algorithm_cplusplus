#include "widget.h"
#include "ui_widget.h"
#include<QTcpServer>
#include<QTcpSocket>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    rSocket=new QTcpSocket(this);
    rSocket->abort();
   ui->showWindow->setText("Start Connect!");
    rSocket->connectToHost(QHostAddress::LocalHost,8000);
    connect(rSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));

  // this->connect(ui->connectButton,SIGNAL(clicked()),this,SLOT(connectServer()));
    this->connect(ui->sendButton,SIGNAL(clicked()),this,SLOT(sendMessage()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::readMessage()//接收信息
{
    QByteArray qba=rSocket->readAll();
    qDebug()<<qba;
    QString str=QVariant(qba).toString();
    ui->showWindow->text().clear();
    ui->showWindow->setText(str);
}

void Widget::sendMessage()//发送信息
{

//    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
//    connect(clientConnection, SIGNAL(disconnected()),
//            clientConnection, SLOT(deleteLater()));
////! [7] //! [8]

//    clientConnection->write(block);
//    clientConnection->disconnectFromHost();

//    ui->showWindow->setText("Get in!");

     //   QByteArray qba;
    QString str=ui->writeWindow->text();
//    QDataStream out(&qba,QIODevice::WriteOnly);
//    out<<(quint16)0;
//    out<<str;
//    out.device()->seek(0);
//    out<<(quint16)(qba.size()-sizeof(quint16));
//    rSocket->write(qba);
    rSocket->write(str.toStdString().c_str(),strlen(str.toStdString().c_str()));
}

void Widget::connectServer()//连接服务器
{


}
