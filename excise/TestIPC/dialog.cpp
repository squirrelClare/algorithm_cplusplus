#include "dialog.h"
#include "ui_dialog.h"
#include<QFileDialog>
#include<QBuffer>
#include<QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    shareMemory.setKey("QShareMemoryExample");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::loadFromFile()
{
    if(shareMemory.isAttached())
        detach();

    ui->label->setText(tr("选择一个图片文件!"));
    QString fileName=QFileDialog::getOpenFileName(0,QString(),QString(),tr("Images(*.png *.jpg)"));
    QImage image;
    if(!image.load(fileName))
    {
        ui->label->setText(tr("选择的文件不是图片,请选择图片文件!"));
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
     // 将图片加载到共享内存
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDataStream out(&buffer);
    out<<image;
    int size=buffer.size();
    if(!shareMemory.create(size))
    {
        ui->label->setText(tr("无法创建共享内存段!"));
        return;
    }
    shareMemory.lock();
    char *to=(char*)shareMemory.data();
    const char *from=buffer.data().data();
    memcpy(to,from,qMin(shareMemory.size(),size));
    shareMemory.unlock();

}

void Dialog::loadFromSharedMemory()
{
    if (!shareMemory.attach())
    {
        ui->label->setText(tr("无法连接到共享内存段,请先加载一张图片"));
    return;
    }
    QBuffer buffer;
    QDataStream in(&buffer);
    QImage image;

    shareMemory.lock();
    buffer.setData((char*)shareMemory.constData(),shareMemory.size());
    buffer.open(QBuffer::ReadOnly);
    in>>image;
    shareMemory.unlock();

    shareMemory.detach();
    ui->label->setPixmap(QPixmap::fromImage(image));


}

// 从文件中加载图片按钮
void Dialog::on_loadFromFileButton_clicked()
{
    loadFromFile();
}

// 从共享内存显示图片
void Dialog::on_loadFromSharedMermoryButton_clicked()
{
    loadFromSharedMemory();
}

void Dialog::detach()
{
    if(!shareMemory.detach())
        ui->label->setText(tr("无法从内存中分离!"));
}
