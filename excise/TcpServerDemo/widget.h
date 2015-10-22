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
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


    QTcpSocket *rSocket;
    QTcpSocket *sSocket;
    QTcpServer *ser;
    private slots:
    void connectClient();
    void readMessage();
    void sendMessage();
    void startConnect();
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
