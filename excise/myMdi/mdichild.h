﻿#ifndef MDICHILD_H
#define MDICHILD_H

#include <QTextEdit>
#include<QCloseEvent>
class MdiChild : public QTextEdit
{
    Q_OBJECT
public:
    explicit MdiChild(QWidget *parent = 0);
    void newFile();//新建文件
    bool loadFile(const QString &fileName);//加载文件
    bool save();//保存操作
    bool saveAs();//另存为操作
    bool saveFile(const QString &fileName);//保存文件
    QString userFriendlyCurrentFile();//提取文件名
    QString currentFile(){return curFile;}//返回当前文件路径
protected:
    void closeEvent(QCloseEvent *event);//关闭事件
private slots:
    void docmentWasModified();//文件被更改时,窗口显示更改状态
private:
    bool mybeSave();//是否需要保存
    void setCurrentFile(const QString &fileName);//设置当前文件
    QString curFile;//保存当前文件路径
    bool isUntitled;//作为当前文件是否被保存到硬盘上的标志

signals:
    
public slots:
    
};

#endif // MDICHILD_H
