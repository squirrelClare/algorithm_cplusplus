#include <QCoreApplication>
#include"solver.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QVector<int>ve({1,34,35,123,54,12,546,75,762,7,234,32,432,464,134,54});
    Solver s(ve,10,762);
    s.Show();
    s.BucketDiv();
    s.Show();
    return a.exec();
}
