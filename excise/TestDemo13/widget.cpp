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
//    QDialog dialog(this);//���ַ����������öԻ�����ʾ����,������һ������.
//    dialog.exec();
}

Widget::~Widget()
{
    delete ui;
}
