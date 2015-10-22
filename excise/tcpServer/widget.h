#ifndef WIDGET_H
#define WIDGET_H
#include<QtNetwork>
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
private:
    QTcpServer *tcpServer;
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:
    void sendMessage();
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
