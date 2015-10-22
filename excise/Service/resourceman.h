#ifndef RESOURCEMAN_H
#define RESOURCEMAN_H

#include<QSqlDatabase>
#include<QtSql>

class ParamManager;
class Downer;

class ResourceMan
{
private:
    QSqlDatabase FDB;  //数据库操作类对象
ParamManager paramMan; //参数管理类对象
QList<QString> fileList;
QStringList paramList;
Downer down;
bool stopFlag; //停止标志，由外部传入
   enum ResourceType{rtUnkown, rtAdver, rtCompany, rtPay, rtShuipai, rtArticle, rtGame}; //资源的类型，rtAdver 广告资源 , rtCommon 普通资源

    void GetFileList(ResourceType resType);//从数据库中读取资源列表
    void ClearFileList();//清除资源列表
    void DownFiles(ResourceType resType);//下载资源文件.
    void DownDDURLPic();
    void DownCityPage();


    bool copyFileToPath(QString sourceDir,QString toDir, bool coverFileIfExist);
    void  setid(QString id);
    bool poststate(QString id);

  public:
    ResourceMan();
    ResourceMan(ParamManager ParamMan,QSqlDatabase FDB,bool stopFlag);
    ~ResourceMan();

    void Execute();


};

#endif // RESOURCEMAN_H
