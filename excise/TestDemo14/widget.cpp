#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->showChildButton,SIGNAL(clicked()),this,SLOT(showChildDialog()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showChildDialog()
{
    QDialog *dialog=new QDialog(this);
    dialog->show();
}

void Widget::on_pushButton_clicked()
{
    close();
    Dialog dlg;
    if(dlg.exec()==QDialog::Accepted)
        show();
}
