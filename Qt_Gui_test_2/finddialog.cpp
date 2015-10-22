#include<QtGui>
#include "finddialog.h"
#include<QLabel>
#include<QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include<QBoxLayout>

FindDialog::FindDialog(QWidget *parent)
    :QDialog(parent)
{
    label=new QLabel(tr("Find &what:"));
    this->lineEdit=new QLineEdit;
    label->setBuddy(lineEdit);

    caseCheckBox=new QCheckBox(tr("Match &case"));
    backWardCheckBox=new QCheckBox(tr("Search &backward"));

    findbutton=new QPushButton(tr("Find"));
    findbutton->setDefault(true);
    findbutton->setEnabled(false);

    closebutton=new QPushButton(tr("Close"));
    connect(lineEdit,SIGNAL(textChanged(const QString&)),
            this,SLOT(enableFindButton(const QString&)));
    connect(findbutton,SIGNAL(clicked()),
            this,SLOT(findClicked()));
    connect(closebutton,SIGNAL(clicked()),
            this,SLOT(close()));

    QHBoxLayout* topLeftLayout=new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    QVBoxLayout* leftlayout=new QVBoxLayout;
    leftlayout->addLayout(topLeftLayout);
    leftlayout->addWidget(caseCheckBox);
    leftlayout->addWidget(backWardCheckBox);

    QVBoxLayout* rightLayout=new QVBoxLayout;
    rightLayout->addWidget(findbutton);
    rightLayout->addWidget(closebutton);
    rightLayout->addStretch();

    QHBoxLayout* mainLayout=new QHBoxLayout;
    mainLayout->addLayout(leftlayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);
    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());
}

void FindDialog::findClicked()
{
    QString text=lineEdit->text();
    Qt::CaseSensitivity cs=caseCheckBox->isChecked()?
                Qt::CaseSensitive:Qt::CaseInsensitive;
    if (backWardCheckBox->isChecked())
    {
        emit findPrevious(text,cs);
    }
    else
    {
        emit findNext(text,cs);
    }
}

void FindDialog::enableFindButton(const QString &text)
{
    findbutton->setEnabled(!text.isEmpty());
}
