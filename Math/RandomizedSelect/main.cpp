#include <QCoreApplication>
#include<QDebug>
#include<QList>
#include"solver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> list;
    list<<791<<46<<98<<41<<37<<4<<17<<89<<13
       <<66<<89<<419<<6364<<173<<614<<62<<46
      <<18<<97<<32<<58<<169<<8<<36<<9<<13<<1;
    Solver *s=new Solver(list,8);
    s->Show();

    return a.exec();
}
