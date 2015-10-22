#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager=new QNetworkAccessManager(this);
    url=QUrl("http://img6.3lian.com/c23/desk3/22/04/24.jpg");//获取下载地址
    QFileInfo infor=QFileInfo(url.path());
    QString fileName(infor.fileName());
    if(fileName.isEmpty())
        fileName="index.html";
   file=new QFile(fileName);
    if(!file->open(QIODevice::WriteOnly))
    {
        qDebug()<<"file open error!";
        delete file;
        file=0;
        return;
    }
  reply=manager->get(QNetworkRequest(url));
    connect(reply,SIGNAL(readyRead()),this,SLOT(DownLoad()));
    connect(reply,SIGNAL(finished()),this,SLOT(FinishDownLoad()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::DownLoad()//下载文件
{
    if(file)
    {
file->write(reply->readAll());
    }
    else
        qDebug()<<"It is failed!";
}

void MainWindow::FinishDownLoad()//下载文件完成后关闭.
{
    delete file;
    file=0;

}

