#include "widget.h"
#include <QApplication>
#include<QTextCodec>
#include<connection.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
      QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
        QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
        if(!createConnection()) return 0;
    Widget w;
    w.show();
    
    return a.exec();
}
