#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
   this-> connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(Change()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Change()
{
    QString str="Hello Word!";
    ui->label->setText(str);
}

