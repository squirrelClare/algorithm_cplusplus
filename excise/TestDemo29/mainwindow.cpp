#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QDomDocument>
#include<QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile file("D:/Program Files/QT/build-TestDemo28-桌面-Debug/test.xml");
    if(!file.open(QIODevice::ReadOnly))
        return;
    else qDebug()<<"Success!";
    QDomDocument doc;
    if(!doc.setContent(&file))
        return;
    else qDebug()<<"Success!";
    QDomNode child=doc.firstChildElement();
    qDebug()<<child.nodeName()<<child.nodeValue();

}

MainWindow::~MainWindow()
{
    delete ui;
}
