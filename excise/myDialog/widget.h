#ifndef WIDGET_H
#define WIDGET_H
#include<QWizardPage>
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:
    void on_pushButton_clicked();//颜色对话框。

    void on_pushButton_3_clicked();//文件对话框。

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::Widget *ui;
    QWizardPage *creatPage1();
    QWizardPage *creatPage2();
    QWizardPage *creatPage3();
};

#endif // WIDGET_H
