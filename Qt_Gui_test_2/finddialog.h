#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include<QString>
class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class FindDialog : public QDialog
{
    Q_OBJECT
public:
//    explicit FindDialog(QWidget *parent = 0);
    FindDialog(QWidget* parent=0);


signals:
    void findNext(const QString& str,Qt::CaseSensitivity cs);
    void findPrevious(const QString& str,Qt::CaseSensitivity cs);
private slots:
    void findClicked();
    void enableFindButton(const QString &text);
private:
    QLabel* label;
    QLineEdit* lineEdit;
    QCheckBox* caseCheckBox;
    QCheckBox* backWardCheckBox;
    QPushButton* findbutton;
    QPushButton* closebutton;
};

#endif // FINDDIALOG_H
