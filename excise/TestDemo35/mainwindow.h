#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QSharedMemory>
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
    //public slots:
    //    void ShowImage();
    //    void LoadImage();

private:
    Ui::MainWindow *ui;
    QSharedMemory sharedMemory;

private slots:

    void ShowImage();
    void LoadImage();
};

#endif // MAINWINDOW_H
