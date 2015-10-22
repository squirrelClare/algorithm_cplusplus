#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QMenu>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->PushBt1->setText(tr("&nihao"));
    ui->PushBt2->setText(tr("帮助(&H)"));
    ui->PushBt2->setIcon(QIcon("D:/Program Files/QT/TestButtonDmeo1/1.jpg"));
    ui->PushBt3->setText(tr("z&oom"));
    QMenu *menu=new QMenu(this);
    menu->addAction(QIcon("D:/Program Files/QT/TestButtonDmeo1/2.jpg"),tr("放大"));
    ui->PushBt3->setMenu(menu);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_PushBt1_toggled(bool checked)
{
    qDebug()<<tr("按钮是否按下")<<checked;
}
