#include "widget.h"
#include "ui_widget.h"
#include<QTcpServer>
#include<QTcpSocket>
#include<QDebug>
#include<QDataStream>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QString str="Start Listen 19999";
    ui->showWindow->setText(str);
    ser=new QTcpServer(this);
    if(  ser->listen(QHostAddress::LocalHost,8000))
    {
        qDebug()<<ser->errorString();
        close();
    }
    connect(ser,SIGNAL(newConnection()),this,SLOT(connectClient()));
connect(ui->sendButton,SIGNAL(clicked()),this,SLOT(sendMessage()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::connectClient()
{
    //ui->showWindow->setText("connectClient");
    rSocket=ser->nextPendingConnection();
    connect(rSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
}

void Widget::readMessage()
{
      ui->showWindow->setText("connectClient");
    QByteArray qba=rSocket->readAll();
    QString str=QVariant(qba).toString();
    ui->showWindow->text().clear();
    ui->showWindow->setText(str);
}

void Widget::sendMessage()
{
    QString str=ui->writeWindow->text();
      rSocket->write(str.toStdString().c_str(),strlen(str.toStdString().c_str()));
}

void Widget::startConnect()
{
}


