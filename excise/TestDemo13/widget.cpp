#include "widget.h"
#include "ui_widget.h"
#include<QDialog>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QDialog *dialog=new QDialog(this);
    dialog->show();
//    QDialog dialog(this);//两种方法都可以让对话框显示出来,而不是一闪而过.
//    dialog.exec();
}

Widget::~Widget()
{
    delete ui;
}
