#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QColorDialog>
#include<QTextCodec>
#include<QObject>
#include<QFileDialog>
#include<QFontDialog>
#include<QInputDialog>
#include<QStringList>
#include<QMessageBox>
#include<QProgressDialog>
#include<QErrorMessage>
#include<QWizard>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{

        QColorDialog dialog(Qt::red,this);
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    dialog.exec();
    QColor color=dialog.currentColor();
    qDebug()<<QObject::tr("颜色的具体信息是:");
    qDebug()<<"color:"<<color;
}

void Widget::on_pushButton_3_clicked()
{
    QStringList filenames=QFileDialog::getOpenFileNames(this,tr("File Dialog"),"D:/",tr("图片文件(*png *jpg);;文本文件(*txt)"));
    qDebug()<<"filenames:"<<filenames;
}

void Widget::on_pushButton_2_clicked()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok,this);
    if(ok)
        ui->pushButton_2->setFont(font);
    else
        qDebug()<<tr("没有选择字体!");
}

void Widget::on_pushButton_4_clicked()
{
    bool ok;
    QString string=QInputDialog::getText(this,tr("Input Qstring Dialog"),
                                         tr("User Name:"),QLineEdit::Normal,tr("admin"),&ok);
    if(ok)qDebug()<<"string:"<<string;
    int value1=QInputDialog::getInt(this,tr("Input int Dialog"),
                                   tr("Please input the number(int) bettwen -1000 and 1000"),100,-1000,1000,10,&ok);
    qDebug()<<"value1"<<value1;
    double value2=QInputDialog::getDouble(this,tr("Input double Dialog"),
                                   tr("Please input the number(double) bettwen -1000 and 1000"),0.00,-1000,1000,2,&ok);
    qDebug()<<"value2"<<value2;
    QStringList items;
    items<<"Item one"<<"Item two";
    QString item=QInputDialog::getItem(this,tr("Input Item Dialog"),tr("Please select a item"),items,0,true,&ok);
    qDebug()<<"item:"<<item;
}

void Widget::on_pushButton_6_clicked()
{
    int ret1=QMessageBox::question(this,tr("Message Dialog"),tr("Do you know Qt?"),QMessageBox::Yes,QMessageBox::No);
    if(ret1==QMessageBox::Yes)
        qDebug()<<tr("问题!");

    int ret2=QMessageBox::information(this,tr("提示对话框"),tr("这是Qt书籍"),QMessageBox::Ok);
    if(ret2==QMessageBox::Ok)
        qDebug()<<tr("提示!");

    int ret3=QMessageBox::warning(this,tr("警告对话框"),tr("不能提前结束!"),QMessageBox::Abort);
    if(ret3==QMessageBox::Abort)qDebug()<<tr("警告!");

    int ret4=QMessageBox::critical(this,tr("严重警告"),tr("发现一个严重错误,即将关闭所有文件!"),QMessageBox::YesAll);
    if(ret4==QMessageBox::YesAll)qDebug()<<tr("错误!");

    QMessageBox::about(this,tr("关于对话框"),tr("致力于Qt以及Qt creator的普及工作!"));
}

void Widget::on_pushButton_5_clicked()
{
    QProgressDialog dialog(tr("文件复制进度"),tr("取消"),0,50000,this);
    dialog.setWindowTitle(" 进度对话框");
    dialog.setWindowModality(Qt::WindowModal);
    dialog.show();
    for(int i=0;i<50000;i++)
    {
        dialog.setValue(i);
        QCoreApplication::processEvents();
        if(dialog.wasCanceled()) break;
    }
    dialog.setValue(50000);
    qDebug()<<tr("复制结束！");
}

void Widget::on_pushButton_7_clicked()
{
    QErrorMessage *dialog=new QErrorMessage(this);
    dialog->setWindowTitle(tr("错误信息对话框"));
    dialog->showMessage(tr("这是错误信息!"));
}

QWizardPage *Widget::creatPage1()
{
    QWizardPage *page=new QWizardPage();
    page->setTitle(tr("介绍"));
    return page;
}

QWizardPage *Widget::creatPage2()
{
    QWizardPage *page=new QWizardPage();
    page->setTitle(tr("用户选择"));
    return page;
}

QWizardPage *Widget::creatPage3()
{
    QWizardPage *page=new QWizardPage();
    page->setTitle(tr("结束"));
    return page;
}

void Widget::on_pushButton_8_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(tr("向导对话框"));
    wizard.addPage(creatPage1());
    wizard.addPage(creatPage2());
    wizard.addPage(creatPage3());
    wizard.exec();

}
