#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mdichild.h"
#include<QMdiSubWindow>
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    actionSeparator=new QAction(this);
    actionSeparator->setSeparator(true);
    updataMenus();
    connect(ui->mdiArea,SIGNAL(subWindowActivated(QMdiSubWindow*))
            ,this,SLOT(updataMenus()));

    windowMapper=new QSignalMapper(this);
    connect(windowMapper,SIGNAL(mapped(QWidget*))
            ,this,SLOT(setActiveSubWindow(QWidget*)));
    updataWindowMenu();
    connect(ui->menuW,SIGNAL(aboutToShow()),this,SLOT(updataWindowMenu()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
//    MdiChild *child=new MdiChild;
//    ui->mdiArea->addSubWindow(child);
    MdiChild *child=createMdiChild();
    child->newFile();
    child->show();
}

void MainWindow::updataMenus()
{
    bool hasMdiChild=(activeMdiChild()!=0);
    ui->actionSave->setEnabled(hasMdiChild);
    ui->actionSaveAs->setEnabled(hasMdiChild);
    ui->actionPaste->setEnabled(hasMdiChild);
    ui->actionClose->setEnabled(hasMdiChild);
    ui->actionCloseAll->setEnabled(hasMdiChild);
    ui->actionTitle->setEnabled(hasMdiChild);
    ui->actionCascade->setEnabled(hasMdiChild);
    ui->actionPrevious->setEnabled(hasMdiChild);

    actionSeparator->setVisible(hasMdiChild);
   bool hasSelection=(activeMdiChild()&&activeMdiChild()
                      ->textCursor().hasSelection());
   ui->actionCut->setEnabled(hasSelection);
   ui->actionCopy->setEnabled(hasSelection);
   ui->actionUndo->setEnabled(activeMdiChild()&&
                              activeMdiChild()->document()->isUndoAvailable());
   ui->actionRedo->setEnabled(activeMdiChild()
                              &&activeMdiChild()->document()->isRedoAvailable());
}

void MainWindow::setActiveSubWindow(QWidget *window)
{
    if(!window)
        return;
    ui->mdiArea->setActiveSubWindow(qobject_cast
                                    <QMdiSubWindow*>(window));
}

MdiChild *MainWindow::activeMdiChild()
{
    if(QMdiSubWindow *activeSubWindow=ui->mdiArea
            ->activeSubWindow())
        return qobject_cast<MdiChild *>(activeSubWindow->widget());
    return 0;
}

MdiChild *MainWindow::createMdiChild()
{
    MdiChild *child=new MdiChild;
    ui->mdiArea->addSubWindow(child);
    connect(child,SIGNAL(copyAvailable(bool)),
            ui->actionCut,SLOT(setEnabled(bool)));
    connect(child,SIGNAL(copyAvailable(bool)),ui->actionCopy,
            SLOT(setEnabled(bool)));
    connect(child->document(),SIGNAL(undoAvailable(bool)),
            ui->actionUndo,SLOT(setEnabled(bool)));
    connect(child->document(),SIGNAL(redoAvailable(bool))
            ,ui->actionRedo,SLOT(setEnabled(bool)));
    return child;
}

QMdiSubWindow *MainWindow::findMdiChild(const QString &fileName)
{
    QString canonicalFilePath=QFileInfo(fileName).canonicalFilePath();
    foreach (QMdiSubWindow *window, ui->mdiArea->subWindowList()) {
        MdiChild *mdiChild=qobject_cast<MdiChild*>(window->widget());
        if(mdiChild->currentFile()==canonicalFilePath)
        return window;
    }
    return 0;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName=QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty()){
        QMdiSubWindow *existing=findMdiChild(fileName);
        if(existing){
            ui->mdiArea->setActiveSubWindow(existing);
            return;
        }
        MdiChild *child=createMdiChild();
        if(child->loadFile(fileName)){
            ui->statusBar->showMessage(tr("打开文件成功"),2000);
            child->show();
        }else{
            child->close();
        }
    }
}

void MainWindow::updataWindowMenu()
{
    ui->menuW->clear();
    ui->menuW->addAction(ui->actionClose);
    ui->menuW->addAction(ui->actionCloseAll);
    ui->menuW->addSeparator();
    ui->menuW->addAction(ui->actionTitle);
    ui->menuW->addAction(ui->actionCascade);
    ui->menuW->addSeparator();
    ui->menuW->addAction(ui->actionNext);
    ui->menuW->addAction(ui->actionPrevious);
    ui->menuW->addAction(actionSeparator);
    QList<QMdiSubWindow*>windows=ui->mdiArea->subWindowList();
    actionSeparator->setVisible(!windows.isEmpty());

    for(int i=0;i<windows.size();i++){

        MdiChild *child=qobject_cast<MdiChild*>(windows.at(i)->widget());
        QString text;
        if(i<9){
            text=tr("&%1 %2").arg(i+1).arg(child->userFriendlyCurrentFile());
        }else{
            text=tr("%1 %2").arg(i+1)
                    .arg(child->userFriendlyCurrentFile());
        }
        QAction *action=ui->menuW->addAction(text);
        action->setCheckable(true);
        action->setChecked(child==activeMdiChild());
        connect(action,SIGNAL(triggered()),windowMapper
                ,SLOT(map()));
        windowMapper->setMapping(action,windows.at(i));
    }
}
