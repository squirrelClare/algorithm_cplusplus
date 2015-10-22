#ifndef WIDGET_H
#define WIDGET_H
#include<QDialog>
#include <QWidget>
#include<dialog.h>
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
    public slots:
        void showChildDialog();
private slots:
        void on_pushButton_clicked();
};

#endif // WIDGET_H
