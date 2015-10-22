#include "const.h"

Const::Const()
{


    QString const SysCfgFile = "Private.ini"; //定义全局配置文件的名称
    QString const DownTempDir = "TempDown/ ";//定义全局临时目录
    QString const UPDATE_SOFT_PATH_TEMP = "TempDown/Soft/"; //定义软件升级用的临时目录
    QString const ALL_DOWN_SOFT_FILE = "all.dat"; //定义软件全部下载完成的标志文件名称
    QString const ParamServer = "http://manage.easytoo.net/backend/interface/GetTerminalSetting";     //投产环境
     //ParamServer = "http://dev.iberry_ext.com/backend/interface/GetTerminalSetting";    //测试环境
    QString const FTPServer = "manage.easytoo.net";    //真实环境FTP
    QString const FTPPlayInfoDir = "/playinfo";
    QString const FTPUser = "iberry";
    QString const FTPPass = "123456";
     //FTPServer = "dev.iberry_ext.com";


    QString constuser="root";//定义数据库的用户名
    QString constpassword="123456";//定义数据库密码
    QString constname="easytoo";//定义数据库的名称
}

Const::~Const()
{
}
