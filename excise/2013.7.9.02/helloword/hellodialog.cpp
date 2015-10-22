#include "hellodialog.h"
#include "ui_hellodialog.h"
HelloDialog::HelloDialog(QWidget *parent) :
    QDialog(parent)
{
    ui=new UI::HelloDialog;
    ui->setupUi(this);
}
