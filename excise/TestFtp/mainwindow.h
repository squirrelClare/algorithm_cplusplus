#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QFtp;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QFtp *ftp;

    private slots:
    void FtpCommandStarted(int);
    void FtpCommandFinished(int, bool);

};

#endif // MAINWINDOW_H
