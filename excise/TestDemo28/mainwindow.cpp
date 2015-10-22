#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDomDocument>
#include<QDomText>
#include<QDebug>
#include<QFile>
#include<QDebug>
#include<QDomProcessingInstruction>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file("test.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate ))
        return;
    else
        qDebug()<<"ths file is existing!";
    QDomDocument doc;
    QDomText text;
    QDomProcessingInstruction instruction;
    instruction=doc.createProcessingInstruction("xml", "version = \'1.0\'");
    doc.appendChild(instruction);
    QDomElement school=doc.createElement("school");


    doc.appendChild(school);

    QDomElement schoolGuangMing=doc.createElement("schoolGuangMing");
    school.appendChild(schoolGuangMing);

    QDomElement grate1=doc.createElement("grate1");
    text=doc.createTextNode("一年级");
    grate1.appendChild(text);
    schoolGuangMing.appendChild(grate1);

    QDomElement student= doc.createElement("student1");
    QDomAttr name=doc.createAttribute("name");
    name.setValue("李明");
    QDomAttr number=doc.createAttribute("number");
    number.setValue("0x12313");
    student.setAttributeNode(name);
    student.setAttributeNode(number);
    schoolGuangMing.appendChild(student);


    QDomElement grate2=doc.createElement("grate2");
    text=doc.createTextNode("二年级");
    grate2.appendChild(text);
    schoolGuangMing.appendChild(grate2);

    QDomElement grate3=doc.createElement("grate3");
    text=doc.createTextNode("三年级");
    grate3.appendChild(text);
    schoolGuangMing.appendChild(grate3);

    QDomElement grate4=doc.createElement("grate4");
    text=doc.createTextNode("四年级");
    grate4.appendChild(text);
    schoolGuangMing.appendChild(grate4);

    QTextStream out( &file );

           doc.save( out, 7 );

        file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
