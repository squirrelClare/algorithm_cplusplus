#ifndef HELLODIALOG_H
#define HELLODIALOG_H

#include <QDialog>
namespace UI {
class HelloDialog;

}
class HelloDialog : public QDialog
{
    Q_OBJECT
public:
    explicit HelloDialog(QWidget *parent = 0);
    
signals:
    
public slots:
private:
    UI::HelloDialog &ui;
    
};

#endif // HELLODIALOG_H
