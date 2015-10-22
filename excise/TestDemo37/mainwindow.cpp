#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTime>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<QTime(0,0,0).secsTo(QTime::currentTime());
    qsrand(1000);
    qDebug()<<(double) qrand();
}

MainWindow::~MainWindow()
{
    delete ui;
}
