#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug()<<ui->lineEdit->text();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button1_clicked()
{
    ui->button1->setText("AAr");

}
