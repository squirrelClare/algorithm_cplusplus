#include "widget.h"
#include "ui_widget.h"
#include<QtNetwork>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl("http://qt.nokia.com"));
    request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");

    QNetworkReply *reply = manager->get(request);
    connect(reply, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(slotError(QNetworkReply::NetworkError)));
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)),
            this, SLOT(slotSslErrors(QList<QSslError>)));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::slotReadyRead()
{
}
