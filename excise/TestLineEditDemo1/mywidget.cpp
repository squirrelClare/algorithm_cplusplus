#include "mywidget.h"
#include "ui_mywidget.h"
#include<QDebug>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    ui->lineEdi2;
    ui->lineEdit3;
    ui->lineEdit1;

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_lineEdi2_returnPressed()
{
    ui->lineEdit3->setFocus();
    qDebug()<<ui->lineEdi2->text();
    qDebug()<<ui->lineEdi2->displayText();
}
