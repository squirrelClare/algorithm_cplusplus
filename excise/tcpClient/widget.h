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
    
private:
    Ui::Widget *ui;
    QTcpSocket *tcpSocket;
    QString message;//存放从服务器接受的字符串
    qint16 blockSize;//存放文件大小信息
private slots:
    void newConnect();//连接服务器
    void readMessage();//接收新数据
    void disPlayError(QAbstractSocket::SocketError);//显示错误.
    void on_pushButton_clicked();
};

#endif // WIDGET_H
