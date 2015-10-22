#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"mythread.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private slots:
    void on_startBtn_clicked();

    void on_stopBtn_clicked();

private:
    Ui::Dialog *ui;
    MyThread mThread;
};

#endif // DIALOG_H
