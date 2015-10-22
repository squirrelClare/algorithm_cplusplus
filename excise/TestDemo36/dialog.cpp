#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_startBtn_clicked()
{
    mThread.start();
    ui->startBtn->setEnabled(false);
    ui->stopBtn->setEnabled(true);
}

void Dialog::on_stopBtn_clicked()
{
    if(mThread.isRunning()){
        mThread.Stop();
        ui->startBtn->setEnabled(true);
        ui->stopBtn->setEnabled(false);
    }

}
