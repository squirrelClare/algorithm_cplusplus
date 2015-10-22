#include <QCoreApplication>
#include<QStringList>
#include<QDebug>
#include<QVariant>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList list;
    list<<"djioqudoique";
    list.append("131231add");
    list.append("e89hheiuy");
    qDebug()<<list<<endl;
    qDebug()<<list.join("");
    return a.exec();
}
