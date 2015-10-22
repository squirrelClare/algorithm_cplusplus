﻿#include "mdichild.h"
#include<QMessageBox>
#include<QTextStream>
#include<QApplication>
#include<QFileInfo>
#include<QFileDialog>
#include<QPushButton>
MdiChild::MdiChild(QWidget *parent) :
    QTextEdit(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
    isUntitled=true;
}

void MdiChild::newFile()
{
    static int sequenceNumber=1;
    isUntitled=true;
    curFile=tr("未命名文档%1.txt").arg(sequenceNumber++);
    setWindowTitle(curFile+"[*]"+tr("-多文档编辑器"));
    connect(document(),SIGNAL(contentsChanged()),this,SLOT(docmentWasModified()));
}

bool MdiChild::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this,tr("多文档编辑器"),
                             tr( "无法读取文件%1:\n%2").arg(fileName)
                             .arg(file.errorString()));
        return false;
    }
    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();
    setCurrentFile(fileName);
    connect(document(),SIGNAL(contentsChanged()),
            this,SLOT(docmentWasModified()));

    return true;
}

bool MdiChild::save()
{
    if(isUntitled)
    {
        return saveAs();
    }
    else
    {
        return saveFile(curFile);
    }
}

bool MdiChild::saveAs()
{
    QString fileName=QFileDialog::
            getSaveFileName(this,tr("另存为"),curFile);
    if(fileName.isEmpty())
        return false;
    return saveFile(fileName);
}

bool MdiChild::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this,tr("多文档编辑器")
                             ,tr("无法写入文件%1:\n%2.").arg(fileName
                                                       ).arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out<<toPlainText();
    QApplication::restoreOverrideCursor();
    setCurrentFile(fileName);
    return true;
}


void MdiChild::docmentWasModified()
{
    setWindowModified(document()->isModified());
}

bool MdiChild::mybeSave()
{
    if(document()->isModified()){
        QMessageBox box;
        box.setWindowTitle(tr("多文档编辑器"));
        box.setText(tr(" 是否保存对<%1>的更改")
                    .arg(userFriendlyCurrentFile()));
        box.setIcon(QMessageBox::Warning);
        QPushButton *yesBtn=box.addButton(tr("是(&Y)"),
                                          QMessageBox::YesRole);
        box.addButton(tr("否(&N)"),QMessageBox::NoRole);
        QPushButton *cancelBtn=box.addButton(tr("取消"),QMessageBox
                                             ::RejectRole);
        box.exec();
        if(box.clickedButton()==yesBtn)
            return save();
        else if(box.clickedButton()==cancelBtn)
            return false;
    }
    return true;
}


void MdiChild::setCurrentFile(const QString &fileName)
{
    curFile=QFileInfo(fileName).canonicalFilePath();
    isUntitled=false;
    document()->setModified(false);
    setWindowModified(false);
    setWindowTitle(userFriendlyCurrentFile()+"[*]");
}


QString MdiChild::userFriendlyCurrentFile()
{
    return QFileInfo(curFile).fileName();
}

void MdiChild::closeEvent(QCloseEvent *event)
{
    if(mybeSave()){
        event->accept();
    }else{
        event->ignore();
    }
}
