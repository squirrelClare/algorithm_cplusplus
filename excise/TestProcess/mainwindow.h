﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QProcess>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    QProcess myProcess;
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
private slots:
    void showResult();
    void showState(QProcess::ProcessState);
    void showError();
    void showFinished(int ,QProcess::ExitStatus);
};

#endif // MAINWINDOW_H
