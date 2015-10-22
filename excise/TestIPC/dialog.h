#ifndef DIALOG_H
#define DIALOG_H

#include<QSharedMemory>
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
public slots:
    void loadFromFile();
    void loadFromSharedMemory();
    
private slots:
    void on_loadFromFileButton_clicked();

    void on_loadFromSharedMermoryButton_clicked();

private:
    Ui::Dialog *ui;
    void detach();

    QSharedMemory shareMemory;
};

#endif // DIALOG_H
