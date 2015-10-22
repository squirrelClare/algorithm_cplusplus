#include"ui_hellodialog.h"
int main(int argc,char *argv[])
{

    QApplication a(argc,argv);
    QDialog dg;
   UI::HelloDialog ui;
    ui.setupUI(&dg);
    dg.show();
    return a.exec();
}
