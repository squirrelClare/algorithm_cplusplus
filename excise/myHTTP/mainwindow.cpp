#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtNetwork>
#include<QTextCodec>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    manager=new QNetworkAccessManager(this);
//    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
//            manager->get(QNetworkRequest(QUrl("http://www.baidu.com")));
    manager=new QNetworkAccessManager(this);
    ui->progressBar->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startRequest(QUrl url)
{
    reply=manager->get(QNetworkRequest(url));
    connect(reply,SIGNAL(readyRead()),this,SLOT(httpReadyRead()));
            connect(reply,SIGNAL(downloadProgress(qint64,qint64)),
                    this,SLOT(updateDataReadProgress(qint64,qint64)));
            connect(reply,SIGNAL(finished()),this,SLOT(httpFinished()));
}

void MainWindow::httpFinished()
{
    delete file;
    file=0;
}

//void MainWindow::replyFinished(QNetworkReply *reply)
//{
//    QTextCodec *codec=QTextCodec::codecForLocale();
//    QString all=codec->toUnicode(reply->readAll());
//    ui->textBrowser->setText(all);

//}


void MainWindow::httpReadyRead()
{
    if(file)
        file->write(reply->readAll());
}

void MainWindow::updateDataReadProgress(qint64 bytesRead, qint64 totalBytes)
{
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesRead);
}

void MainWindow::on_pushButton_clicked()
{
    url=ui->lineEdit->text();
    QFileInfo info(url.path());
    //qDebug()<<url.path();
    QString fileName(info.fileName());
   // qDebug()<<fileName;
    if(fileName.isEmpty())
        fileName="index.html";
    file=new QFile(fileName);
    if(!file->open(QIODevice::WriteOnly))
    {
        qDebug()<<"file open error!";
        delete file;
        file=0;
        return ;
    }

     startRequest(url);
    ui->progressBar->setValue(0);
    ui->progressBar->show();
}
