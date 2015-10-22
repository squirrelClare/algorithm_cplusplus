#ifndef DIALOG_H
#define DIALOG_H
#include<QtGui>
#include <QDialog>
class QLabel;
class QCheckBox;
class QLineEdit;
class QPushButton;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

signals:
    void findNext(const QString &str,Qt::CaseSensitivity cs);
    void findPrevious(const QString &str,Qt::CaseSensitivity cs);
private slots:
    void findClicked();
    void enableFindButton(const QString &text);
private:
    Ui::Dialog *ui;
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox *backwardCheckBox;
    QPushButton *findButton;
    QPushButton *closeButton;
};

#endif // DIALOG_H
