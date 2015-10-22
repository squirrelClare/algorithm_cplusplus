#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
	tcpSocket=new QTcpSocket(this);
	connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
	connect(tcpSocket,SIGNAL(error(QAbstractSocker::SocketError)),this,SLOT(dispalyError(QAbstractSocket::SocketError)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::newConnect()
{
	blockSize=0;//初始化其为0
    tcpSocket->abort();//取消已有的连接
    tcpSocket->connectToHost(ui->hostLineEdit->text(),ui->portLineEdit->text().toInt());
//连接到主机,这里从界面获取主机和端口号.

}
void Widget::readMessage()
{
	QDataStream in(tcpSocket);
	in.setVersion(QDataStream::Qt_4_8);
	//设置数据流的版本,这里要和服务器端相同
	if(blockSize==0)
	{
		//判断接收的数据是否有两个字节也就是文件的大小信息
		//如果有则保存到blockSize中,没有就返回,继续接受数据
        if(tcpSocket->bytesAvailable()<(int)sizeof(quint16))
            return;
        in>>blockSize;

	}
    if(tcpSocket->bytesAvailable()<blockSize)
        return;
    in>>message;
    ui->messageLabel->setText(message);
}

void Widget::disPlayError(QAbstractSocket::SocketError)
{
qDebug()<<tcpSocket->errorString();//输出错误信息
}

void Widget::on_pushButton_clicked()//连接按钮
{
    newConnect();//请求连接
}
