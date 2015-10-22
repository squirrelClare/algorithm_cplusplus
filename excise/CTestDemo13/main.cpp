#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QLabel>
#include <QWidget>
#include <QDebug>
#include <QTextStream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget wid;
    qDebug() << "sizeof widget: " << sizeof(wid)
             << " sizeof qapplication: " << sizeof(a) ;
    QString message;
    QTextStream buf(&message);
    buf << "A QWdget is " << sizeof(wid)
          << " bytes. \nA QObject is " << sizeof(QObject)
          << " bytes. \nA QApplication is " << sizeof(a)
          << " bytes.";
    qDebug() << message;
    QLabel label(message);
    label.show();

    return a.exec();
}
