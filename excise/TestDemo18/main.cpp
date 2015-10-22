#include <QCoreApplication>
#include<QDebug>
#include<QDir>
#include<QMessageBox>
#include<QTextCodec>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF_8"));
//    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF_8"));
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF_8"));


//QMessageBox::warning(0,"PATH",path,QMessageBox::Yes);//查看路径
//    qDebug()<<QDir::currentPath()<<endl;
//    QString str="heihquieyuqiey1h83h6h136khjohui";
//    qDebug()<<str<<endl;
//    str.replace('h','m');
//    qDebug()<<str<<endl;
//    qDebug()<<str.remove(0,7)<<endl;
//    qDebug()<<str;


//    QString path=QDir::currentPath();
//    QDir file;
//    QString dir=file.filePath(path);
//    qDebug()<<path<<endl<<dir<<endl;
//    qDebug()<<endl<<QDir::current()<<endl<<QDir::currentPath();
//    QDir dir("‪C:/Users/lenovo/Desktop/Service/uDial.pas");
//    qDebug()<<dir.path();
//    qDebug()<<dir.absoluteFilePath("‪C:/Users/lenovo/Desktop/Service/uDial.pas");

    QFileInfo info("‪D:/Program Files/Java/jre7/README.txt");
    qDebug()<<info.path();
    qDebug()<< info.absoluteFilePath();
    return a.exec();
}
