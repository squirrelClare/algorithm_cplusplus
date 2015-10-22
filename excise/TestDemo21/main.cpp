#include <QCoreApplication>
#include<QFile>
#include<QDebug>
#include<QDir>
static bool copyFileToPath(QString sourceDir,QString toDir, bool coverFileIfExist)
{
    toDir.replace('\\','/');
    if (sourceDir==toDir){
        return true;
    }
    if (!QFile::exists(sourceDir)){
        return false;
    }
    QDir *createfile     = new QDir;
    bool exist = createfile->exists(toDir);
    if (exist){
        if(coverFileIfExist){
            createfile->remove(toDir);
        }
    }//end if

    if(!QFile::copy(sourceDir,toDir))
    {
        return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDir dir;
    QString strDir1("C:/Users/lenovo/Desktop/OldFile/1.txt");
    QString strDir2("C:/Users/lenovo/Desktop/NewFile/2.txt");
qDebug()<< dir.exists(strDir1);
   qDebug()<< dir.exists(strDir2);
//    bool suc=copyFileToPath(strDir1,strDir2,true);
   bool suc=QFile::copy(strDir1,strDir2);
    if(suc)
        qDebug()<<"YES";
    else
        qDebug()<<"NO";
    return a.exec();
}
