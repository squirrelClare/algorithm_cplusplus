#include<QtGui>
int main(int argc,char *argv[])
{
    QApplication a(argc,argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QWidget *widget=new QWidget(0,Qt::Dialog|Qt::FramelessWindowHint);
    widget->setWindowTitle(QObject::tr(("����widget")));
    QLabel *label=new QLabel(0,Qt::SplashScreen|Qt::WindowStaysOnTopHint);
    label->setWindowTitle(QObject::tr(("����label")));
    label->setText(QObject::tr(("���Ǵ���")));
    label->resize(180,20);
    QLabel *label2=new QLabel(widget);
    label2->setText(QObject::tr(("label2:�Ҳ��Ƕ�������,ֻ��wiget�� �Ӳ���")));
    label2->resize(250,20);
    label->show();
    widget->show();
    int hex=a.exec();
    delete label;
    delete widget;
    return hex;
}
