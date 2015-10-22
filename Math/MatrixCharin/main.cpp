#include <QCoreApplication>
#include"matrixchainorder.h"
#include<QVector>
#include<QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QVector<int> vec({30,35,15,5,10,20,25});
    MatrixChainOrder m(&vec);
    qDebug()<<m().first<<endl<<m().second<<endl;
    return a.exec();
}
