#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFtp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ftp=new QFtp(this);
    ftp->connectToHost("ftp.qt.nokia.com");
    ftp->login();
    ftp->cd("qt");
    ftp->get("INSTALL");
    ftp->close();
    connect(ftp,SIGNAL(commandStarted(int)),this,SLOT(FtpCommandStarted(int)));
            connect(ftp,SIGNAL(commandFinished(int,bool)),this,SLOT(FtpCommandFinished(int,bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FtpCommandStarted(int)
{
    int id=ftp->currentCommand();
    switch (id)
    {
    case QFtp::ConnectToHost:
        ui->label->setText(tr("正在连接服务器!...."));
        break;
    case QFtp::Login:
        ui->label->setText(tr("正在登陆......"));
        break;
    case QFtp::Get:
        ui->label->setText(tr("正在下载......"));
        break;
    case QFtp::Close:
        ui->label->setText(tr("正在关闭连接...."));
    }
}

void MainWindow::FtpCommandFinished(int,bool error)
{
    if(ftp->currentCommand()==QFtp::ConnectToHost)
    {
        if(error)
            ui->label->setText(tr("连接服务器出现错误:%1").arg(ftp->errorString()));
        else
            ui->label->setText(tr("连接到服务器成功!"));
    }
    else if(ftp->currentCommand()==QFtp::Login)
    {
        if(error)
            ui->label->setText(tr("登陆出现错误:%1").arg(ftp->errorString()));
        else
            ui->label->setText(tr("登陆成功"));
    }
    else if(ftp->currentCommand()==QFtp::Get)
    {
        if(error)
            ui->label->setText(tr("现在出现错误:%1").arg(ftp->errorString()));
        else
            ui->label->setText(tr("下载完成!"));
    }
    else if(ftp->currentCommand()==QFtp::Close)
        ui->label->setText(tr("已经关闭连接!"));
}
