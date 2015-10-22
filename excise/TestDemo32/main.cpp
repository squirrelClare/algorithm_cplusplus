#include <QCoreApplication>
#include<QFile>
#include<QDataStream>
#include<QDir>
#include<QDebug>
bool CopyFile(QString fromDir,QString toDir, bool coverFileIfExist);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString strFrom="‪D:/json/";
    QString strTo="D:/Media/";
    bool success=CopyFile(strFrom,strTo,true);
    if(success)qDebug()<<"Successs";
                         else qDebug()<<"Failed";
    return a.exec();
  }
bool CopyFile(QString sourceDir ,QString toDir, bool coverFileIfExist)
 {
     toDir.replace("\\","/");
     if (sourceDir == toDir){
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

     if(!QFile::copy(sourceDir, toDir))
     {
         return false;
     }
     return true;
 }
