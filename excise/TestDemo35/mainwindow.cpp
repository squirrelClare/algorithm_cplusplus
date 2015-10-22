#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QProcess>
#include<QImage>
#include<QBuffer>
#include<QDataStream>
#include<QSharedMemory>
#include<QDebug>
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sharedMemory.setKey("QSharedMemoryExample");
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(ShowImage()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(LoadImage()));

}

void MainWindow::LoadImage()
{
    if(sharedMemory.isAttached())
        sharedMemory.detach();
    ui->label->setText(tr("选择一个图片文件！"));
    //读入图片文件
    QString fileName=QFileDialog::getOpenFileName(0,QString(),QString(),tr("Image(*.jpg *.png)"));
//    qDebug()<<fileName;
    QImage image;
    if(!image.load(fileName)){
        qDebug()<<"Load image failed!";
        return;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));


    QBuffer buffer;
    if(!buffer.open(QBuffer::ReadWrite)){
        qDebug()<<"buffer can not be open";
        return;
    }
    QDataStream out(&buffer);
    out<<image;

    int size=buffer.size();
    qDebug()<<size;


    if(!sharedMemory.create(size)){
        ui->label->setText(tr("无法创建共享内存段."));
        return;
    }else{
        qDebug()<<"Create successfull!";
    }
    sharedMemory.lock();
    char *to=(char*)sharedMemory.data();
    const char*from=buffer.data().data();
    memcpy(to,from,qMin(sharedMemory.size(),size));
    sharedMemory.unlock();
    buffer.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowImage()
{
    if(!sharedMemory.attach()){
        qDebug()<<"The sharedMemory is not attached.";
        return;
    }
    QBuffer buffer;
    QImage image;
    QDataStream in(&buffer);

    sharedMemory.lock();
    buffer.setData((char*)sharedMemory.constData(),sharedMemory.size());
    buffer.open(QBuffer::ReadOnly);
    in>>image;
    sharedMemory.unlock();
    sharedMemory.detach();
    buffer.close();
    ui->label->setPixmap(QPixmap::fromImage(image));
}

//void MainWindow::on_pushButton_clicked()
//{
//    ShowImage();
//}

//void MainWindow::on_pushButton_2_clicked()
//{
//    LoadImage();
//}
