#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QtNetwork>
#include<QUrl>
#include<QFile>
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

    QNetworkAccessManager *manager;
    QUrl url;
    QFile *file;
    QNetworkReply *reply;
    
private:
    Ui::MainWindow *ui;
public slots:
    void  DownLoad();
    void  FinishDownLoad();
};

#endif // MAINWINDOW_H
