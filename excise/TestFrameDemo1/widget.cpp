#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap("C:/Users/lenovo/Desktop/picture1.jpg"));
    ui->stackedWidget;
    ui->listWidget;
    ui->toolBox;
}

Widget::~Widget()
{
    delete ui;
}
