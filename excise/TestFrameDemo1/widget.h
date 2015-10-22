﻿#ifndef WIDGET_H
#define WIDGET_H
#include<QPixmap>
#include <QWidget>
#include<QListWidget>
#include<QStackedWidget>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
