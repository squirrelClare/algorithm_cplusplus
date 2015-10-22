#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"mdichild.h"
#include <QMainWindow>
#include<QMdiSubWindow>
#include<QSignalMapper>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_actionNew_triggered();
    void updataMenus();
    void setActiveSubWindow(QWidget *window);

    void on_actionOpen_triggered();
    void updataWindowMenu();

private:
    Ui::MainWindow *ui;
    QAction *actionSeparator;//间隔器
    MdiChild *activeMdiChild();//活动窗口
    MdiChild *createMdiChild();
    QMdiSubWindow *findMdiChild(const QString &fileName);
    QSignalMapper *windowMapper;
};

#endif // MAINWINDOW_H
