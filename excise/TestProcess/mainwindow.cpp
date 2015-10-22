#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&myProcess,SIGNAL(readyRead()),this,SLOT(showResult()));
    connect(&myProcess,SIGNAL(stateChanged(QProcess::ProcessState)),this,SLOT(showState(QProcess::ProcessState)));
    connect(&myProcess,SIGNAL(error(QProcess::ProcessError)),this,SLOT(showError()));
    connect(&myProcess,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(showFinished(int,QProcess::ExitStatus)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString program="cmd.exe";
    QStringList arguments;
    arguments<<"/c dir&pause";
    myProcess.start(program,arguments);
  //  myProcess.start("BaiduPlayer.exe","D:/program files (x86)/Baidu/BaiduPlayer/1.19.0.161/");
}

void MainWindow::showResult()
{
    qDebug()<<"showResult"<<endl<<QString(myProcess.readAll());
}

void MainWindow::showState(QProcess::ProcessState state)
{
    qDebug()<<"showState:";
    if(state==QProcess::NotRunning)
        qDebug()<<"Not Running";
    else if(state==QProcess::Starting)
        qDebug()<<"Starting";
    else
        qDebug()<<"Running";
}

void MainWindow::showError()
{
    qDebug()<<"showError:"<<endl<<myProcess.errorString();
}

void MainWindow::showFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    qDebug() << "showFinished: " << endl << exitCode << exitStatus;


}
