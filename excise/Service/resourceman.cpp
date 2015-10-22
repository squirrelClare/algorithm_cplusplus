#include "resourceman.h"


ResourceMan::ResourceMan(ParamManager paramMan,QSqlDatabase FDB,bool stopFlag)
{

     this ->paramList=QStringList();
     this ->FDB=FDB;
     this ->paramMan=paramMan;
     this ->stopFlag=stopFlag;
}

void ResourceMan::GetFileList(ResourceType resType)
{
    QString sql;
    QSqlQuery query;
    if (!FDB.isOpen())
        ClearFileList();
    switch (resType) {
    case rtAdver:
        sql=" SELECT et_attachment.id AS id,et_attachment.path  FROM et_advertisement_list "
                " LEFT JOIN et_list_item ON et_advertisement_list.id = et_list_item.list_id "
                   " LEFT JOIN et_advertisement ON et_list_item.advertisement_id = et_advertisement.id "
                   " LEFT JOIN et_attachment ON et_advertisement.attachment_id = et_attachment.id "
                  " LEFT JOIN et_terminal ON et_terminal.group_id = et_advertisement_list.group_id "
                   " WHERE  et_advertisement.flag = 1 AND  et_advertisement.audit=1 AND et_terminal.id =" + paramMan.MachineID + " "
                   " AND advertisement_id NOT IN(SELECT advertisement_id FROM et_advertisement_ignore WHERE terminal_id=" + paramMan.MachineID + ") "
                   " and et_attachment.id>0 and et_attachment.id not in (select id from et_attachment_downed)"
                  " UNION all"
                  " SELECT  et_attachment.id as id, et_attachment.path"
                  " FROM et_advertisement,et_advertisement_ignore,et_attachment"
                  " where et_attachment.id =  et_advertisement.attachment_id"
                  " and et_advertisement.flag = 1 AND  et_advertisement.audit=1"
                  " and et_advertisement.id in (et_advertisement_ignore.advertisement_id )"
                  " and et_advertisement_ignore.terminal_id="+paramMan.MachineID+
                   " UNION "
                   " SELECT et_attachment.id AS id,et_attachment.path  FROM et_advertisement_self "
                   " LEFT JOIN et_advertisement_terminal ON et_advertisement_terminal.advertisement_id=et_advertisement_self.id "
                   " LEFT JOIN et_attachment ON et_attachment.id=et_advertisement_self.attachment_id "
                  " WHERE et_advertisement_terminal.terminal_id=" + paramMan.MachineID + " "
                   " and et_attachment.id>0 and et_attachment.id not in (select id from et_attachment_downed)";
        break;
    case rtCompany:
        sql=" SELECT et_attachment.id AS id,et_attachment.path FROM  et_company  inner JOIN et_attachment ON"
     " et_company.logo_id=et_attachment.id and et_attachment.id>0 and et_attachment.id not in"
       " (select id from et_attachment_downed) WHERE et_company.id IN( SELECT id FROM et_company  WHERE area_id IN"
       " (SELECT DISTINCT `a`.id FROM `et_area` AS `a`,`et_area` AS `b`     WHERE `a`.`left_value` BETWEEN `b`.`left_value`"
       " AND `b`.`right_value` AND b.id=" + QString::number(paramMan.AREA) + ") )"
       " union"
      " SELECT et_attachment.id AS id,et_attachment.path FROM  et_company  inner JOIN et_attachment ON"
       " et_company.attachment_id=et_attachment.id and et_attachment.id>0 and et_attachment.id not in"
      " (select id from et_attachment_downed) WHERE et_company.id IN( SELECT id FROM et_company  WHERE"
      " area_id IN (SELECT DISTINCT `a`.id FROM `et_area` AS `a`,`et_area` AS `b`"
       " WHERE `a`.`left_value` BETWEEN `b`.`left_value` AND `b`.`right_value` AND b.id=" + QString::number(paramMan.AREA) + ") )"
       " UNION"
       " SELECT et_attachment.id AS id,et_attachment.path FROM  et_company_photo  inner JOIN et_attachment ON"
       " et_company_photo.attachment_id=et_attachment.id and et_attachment.id>0 and et_attachment.id not in"
       " (select id from et_attachment_downed) WHERE et_company_photo.company_id IN( SELECT id FROM et_company  WHERE"
       " area_id IN (SELECT DISTINCT `a`.id FROM `et_area` AS `a`,`et_area` AS `b`"
       " WHERE `a`.`left_value` BETWEEN `b`.`left_value` AND `b`.`right_value` AND b.id=" + QString::number(paramMan.AREA) + ") )"
      " UNION"
       " SELECT et_attachment.id AS id,et_attachment.path FROM  et_discount inner JOIN et_attachment"
       " ON et_discount.attachment_id=et_attachment.id  and  et_attachment.id>0 and et_attachment.id"
       " not in (select id from et_attachment_downed) WHERE et_discount.company_id IN"
       " ( SELECT id FROM et_company  WHERE area_id"
       " IN (SELECT DISTINCT `a`.id FROM `et_area` AS `a`,`et_area` AS `b`"
       " WHERE `a`.`left_value` BETWEEN `b`.`left_value` AND `b`.`right_value` AND b.id=" + QString::number(paramMan.AREA) + ") )";
        break;
    case rtPay:
    sql= " SELECT  et_attachment.id AS id,et_attachment.path FROM  ("
          " SELECT DISTINCT a.id AS categoryid,a.title,a.up_img_id,a.down_img_id,a.oper FROM pay_category AS a,pay_category AS b "
            " WHERE  b.left_value BETWEEN a.left_value AND a.right_value AND a.parent_id<>0 "
            " AND b.id IN (SELECT category_id FROM pay_product WHERE FIND_IN_SET(" + QString::number(paramMan.AREA) + ",area_ids) AND Flag=1 )) AS t "
           " LEFT JOIN et_attachment ON t.up_img_id=et_attachment.id OR t.down_img_id=et_attachment.id "
           " WHERE t.up_img_id<>0 OR t.down_img_id<>0 "
           " and et_attachment.id>0 and et_attachment.id not in (select id from et_attachment_downed)"
            " UNION "
            " SELECT  et_attachment.id AS id,et_attachment.path FROM  ("
            " SELECT id,title,product_img_id,product_info_id FROM pay_product WHERE FIND_IN_SET(" + QString::number(paramMan.AREA) + ",area_ids) AND Flag=1 "
            " ) AS tt "
            " LEFT JOIN et_attachment ON tt.product_img_id=et_attachment.id OR tt.product_info_id=et_attachment.id "
            " WHERE tt.product_img_id<>0 OR tt.product_info_id<>0 "
            " and et_attachment.id>0 and et_attachment.id not in (select id from et_attachment_downed)";
    break;
    case rtShuipai:
    sql="SELECT et_attachment.id AS id,et_attachment.path FROM  et_mansion "
                          "LEFT JOIN et_attachment ON et_mansion.attachment_id=et_attachment.id "
                         "WHERE et_mansion.id=(select mansion_id from et_terminal where id="+paramMan.MachineID+") "
                          "and et_attachment.id>0 and et_attachment.id not in (select id from et_attachment_downed)";
    break;
    case rtArticle:
    sql = " SELECT et_attachment.id AS id,et_attachment.path FROM  et_article"
          " LEFT JOIN et_attachment ON et_article.attachment_id=et_attachment.id OR et_article.source=et_attachment.id"
             " WHERE et_article.area_id IN("
            " SELECT DISTINCT `a`.id FROM `et_area` AS `a`,`et_area` AS `b` WHERE `a`.`left_value` BETWEEN "
            " `b`.`left_value` AND `b`.`right_value` AND b.id=" + QString::number(paramMan.AREA) + ")"
           " and et_attachment.id>0 and et_attachment.id not in (select id from et_attachment_downed)";
    break;
    case rtGame:
    sql=" SELECT et_attachment.id AS id,et_attachment.path FROM  et_game"
           " LEFT JOIN et_attachment ON et_game.attachment_id=et_attachment.id WHERE et_attachment.id>0 and"
            " et_attachment.id not in (select id from et_attachment_downed) "
            " UNION"
             " SELECT et_attachment.id AS id,et_attachment.path FROM  et_game_item"
             " LEFT JOIN et_attachment ON et_game_item.attachment_id=et_attachment.id WHERE et_attachment.id>0"
            " and et_attachment.id not in (select id from et_attachment_downed) ";
    break;
    default:
        sql="";
        break;
    }
    query.exec(sql);
    if(!query.isActive()) return;
    while(query.next())
    {
        fileList.append(query.value(1).toString());
    }

}

void ResourceMan::ClearFileList()
{
    fileList.clear();
}


void ResourceMan::DownCityPage()
{   QString sql;
    QString updatesql;
    int id;
  QString  Locationimg,Showsimg,Showbimg,Subjectimg,Detailimg1,Detailimg2,qrimg,localpath,tmplocal;
  QString ddstr;
  bool downded,downSucc;


    if(!FDB.isOpen()) return;
    sql="select * from ET_CITYPAGES where Locationimg like ""http%"" or Showsimg like ""http%"" or qrimg like ""http%"" or Showbimg  like ""http%"" or Subjectimg  like ""http%"" or Detailimg1 like ""http%"" or Detailimg2 like ""http%""";
   updatesql="update ET_CITYPAGES set alldown=""1"" where (Locationimg like ""%iberry%bin%"" and Showsimg like ""%iberry%bin%"" and Showbimg  like ""%iberry%bin%"" and Subjectimg  like ""%iberry%bin%"" "
      "and  Detailimg1 like ""%iberry%bin%"" and  Detailimg2 like ""%iberry%bin%"") and not"
      " (Locationimg like ""http%"" or Showsimg like ""http%"" or Showbimg  like ""http%"""
      "or Subjectimg  like ""http%"" or Detailimg1 like ""http%"" or Detailimg2 like ""http%"")";

QSqlQuery query(FDB);
query.exec(sql);
while(query.next())
{
    id=query.value(query.record().indexOf("id")).toInt();
     Locationimg=query.value(query.record().indexOf("Locationimg")).toString();
     Showsimg=query.value(query.record().indexOf("Showsimg")).toString();
     Showbimg=query.value(query.record().indexOf("Showbimg")).toString();
     Subjectimg=query.value(query.record().indexOf("Subjectimg")).toString();
     Detailimg1=query.value(query.record().indexOf("Detailimg1")).toString();
     Detailimg2=query.value(query.record().indexOf("Detailimg2")).toString();
     qrimg=query.value(query.record().indexOf("qrimg")).toString();


     if(Locationimg.indexOf("http")>0)
     {
         downded=true;
          localpath=QDir::currentPath() + Locationimg.remove(0,8).replace('/','\\');
          QDir dir;
         if(!dir.exists(localpath))dir.mkdir(localpath);
         tmplocal=QDir::currentPath() +"TempDown\\"+Locationimg.remove(0,8).replace('/','\\');
           if(!dir.exists(tmplocal))dir.mkdir(tmplocal);

           QFileInfo info(localpath);
           if(!info.exists())
           {
               downSucc=down.Downfile(tmplocal, (Locationimg)); //下载文件到临时目录
               if(downSucc)
               {
                            copyFileToPath(tmplocal, localpath, true);
               }
               else {
                   downded=false;
               }


           }
           if(downded)
               query.exec("update et_ddurlset set imgsrc100=''"+localpath+"where id="+QString::number(id)+'');

          }
     if(true)
     {
         QStringList ss;
         ss=Showsimg.split(',');
         ddstr="";

         for(int i=0;i<ss.length()-1;i++)
         {
             if(ss.at(i).indexOf("http")>0)
             {
                 downded=true;
                  localpath=QDir::currentPath() + Showsimg.remove(0,8).replace('/','\\');
                  QDir dir;
                 if(!dir.exists(localpath))dir.mkdir(localpath);
                 tmplocal=QDir::currentPath() +"TempDown\\"+Showsimg.remove(0,8).replace('/','\\');
                   if(!dir.exists(tmplocal))dir.mkdir(tmplocal);

                   QFileInfo info(localpath);
                   if(!info.exists())
                   {
                       downSucc=down.Downfile(tmplocal, (Showsimg)); //下载文件到临时目录
                       if(downSucc)
                       {
                                    copyFileToPath(tmplocal, localpath, true);
                       }
                       else {
                           downded=false;
                       }
                 }
                   if(downded)
                       ddstr=ddstr+localpath+',';
                   else
                       ddstr=ddstr+ss.at(i);
         }
             else if(ss.at(i).indexOf("bin")>0)
                 ddstr=ddst+ss.at(i)+',';

     }
        ss.clear();
         query.exec("update ET_CITYPAGES set Showsimg="""+ddstr+""" where id="+QString::number(id)+"");

}

     if	(Showbimg.indexOf("http")>0)
     {
     downded=True;
     localpath=QDir::currentPath()	+ Showbimg.remove(0,8).replace('/','\\');
     QDir	dir;
     if(!dir.exists(localpath))dir.mkdir(localpath);
     tmplocal=QDir::currentPath() +"TempDown\\"+Showsimg.remove(0,8).replace('/','\\');
     if(!dir.exists(tmplocal))dir.mkdir(tmplocal);
     QFileInfo info(localpath);
                        if(!info.exists())
                        {
                            downSucc=down.Downfile(tmplocal, (Showsimg)); //下载文件到临时目录
                            if(downSucc)
                            {
                                         copyFileToPath(tmplocal, localpath, true);
                            }
                            else {
                                downded=false;
                            }
                      }
     if(downded)
     query.exec("update ET_CITYPAGES	set	Showbimg="""+localpath+""" where id="+QString::number(id)+"");
     }

     if	(qrimg.indexOf("http")>0)
     {
     downded=True;
     localpath=QDir::currentPath()	+ qrimg.remove(0,8).replace('/','\\');
     QDir	dir;
     if(!dir.exists(localpath))dir.mkdir(localpath);
     tmplocal=QDir::currentPath() +"TempDown\\"+qrimg.remove(0,8).replace('/','\\');
     if(!dir.exists(tmplocal))dir.mkdir(tmplocal);
     QFileInfo info(localpath);
                        if(!info.exists())
                        {
                            downSucc=down.Downfile(tmplocal, (qrimg)); //下载文件到临时目录
                            if(downSucc)
                            {
                                         copyFileToPath(tmplocal, localpath, true);
                            }
                            else {
                                downded=false;
                            }
                      }
     if(downded)
     query.exec("update ET_CITYPAGES	set	qrimg="""+localpath+""" where id="+QString::number(id)+"");
     }

     if	(Subjectimg.indexOf("http")>0)
     {
     downded=True;
     localpath=QDir::currentPath()	+ Subjectimg.remove(0,8).replace('/','\\');
     QDir	dir;
     if(!dir.exists(localpath))dir.mkdir(localpath);
     tmplocal=QDir::currentPath() +"TempDown\\"+Subjectimg.remove(0,8).replace('/','\\');
     if(!dir.exists(tmplocal))dir.mkdir(tmplocal);
     QFileInfo info(localpath);
                        if(!info.exists())
                        {
                            downSucc=down.Downfile(tmplocal, (Subjectimg)); //下载文件到临时目录
                            if(downSucc)
                            {
                                         copyFileToPath(tmplocal, localpath, true);
                            }
                            else {
                                downded=false;
                            }
                      }
     if(downded)
     query.exec("update ET_CITYPAGES	set	Subjectimg="""+localpath+""" where id="+QString::number(id)+"");
     }

     if	(Detailimg1.indexOf("http")>0)
     {
     downded=True;
     localpath=QDir::currentPath()	+ Detailimg1.remove(0,8).replace('/','\\');
     QDir	dir;
     if(!dir.exists(localpath))dir.mkdir(localpath);
     tmplocal=QDir::currentPath() +"TempDown\\"+Detailimg1.remove(0,8).replace('/','\\');
     if(!dir.exists(tmplocal))dir.mkdir(tmplocal);
     QFileInfo info(localpath);
                        if(!info.exists())
                        {
                            downSucc=down.Downfile(tmplocal, (Detailimg1)); //下载文件到临时目录
                            if(downSucc)
                            {
                                         copyFileToPath(tmplocal, localpath, true);
                            }
                            else {
                                downded=false;
                            }
                      }
     if(downded)
     query.exec("update ET_CITYPAGES	set	Detailimg1="""+localpath+""" where id="+QString::number(id)+"");
     }

     if	(Detailimg2.indexOf("http")>0)
     {
     downded=True;
     localpath=QDir::currentPath()	+ Detailimg2.remove(0,8).replace('/','\\');
     QDir	dir;
     if(!dir.exists(localpath))dir.mkdir(localpath);
     tmplocal=QDir::currentPath() +"TempDown\\"+Detailimg2.remove(0,8).replace('/','\\');
     if(!dir.exists(tmplocal))dir.mkdir(tmplocal);
     QFileInfo info(localpath);
                        if(!info.exists())
                        {
                            downSucc=down.Downfile(tmplocal, (Detailimg2)); //下载文件到临时目录
                            if(downSucc)
                            {
                                         copyFileToPath(tmplocal, localpath, true);
                            }
                            else {
                                downded=false;
                            }
                      }
     if(downded)
     query.exec("update ET_CITYPAGES	set	Detailimg2="""+localpath+""" where id="+QString::number(id)+"");
     }

}
query.exec(updatesql);
}


bool ResourceMan::copyFileToPath(QString sourceDir,QString toDir, bool coverFileIfExist)//文件复制
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


void ResourceMan::DownDDURLPic()
{


      QSqlQuery query(FDB);
      QString sql;
     QString showpic,imgsrc100,imgsrc220,localpath,tmplocal;
     int id;
     bool downded,downSucc;

      if(!FDB.isOpen())return;
      sql="select * from et_ddurlset where showpic like ""http%"" or imgsrc100 like ""http%"" or imgsrc220 like ""http%""";
      query.exec(sql);
      if(!query.isActive()) return;
      while(query.next())
      {
        id=query.value(query.record().indexOf("id")).toInt();
        showpic=query.value(query.record().indexOf("showpic")).toString();
        imgsrc100=query.value(query.record().indexOf("imgsrc100")).toString();
        imgsrc220=query.value(query.record().indexOf("imgsrc220")).toString();
        if(showpic.indexOf("http")>0)
        {
            downded=true;
         localpath=QDir::currentPath()	+ showpic.remove(0,8).replace('/','\\');
         QDir	dir;
         if(!dir.exists(localpath))dir.mkdir(localpath);
         tmplocal=QDir::currentPath() +"TempDown\\"+showpic.remove(0,8).replace('/','\\');
         if(!dir.exists(tmplocal))dir.mkdir(tmplocal);
         QFileInfo info(localpath);
                            if(!info.exists())
                            {
                                downSucc=down.Downfile(tmplocal, (showpic)); //下载文件到临时目录
                                if(downSucc)
                                {
                                             copyFileToPath(tmplocal, localpath, true);
                                }
                                else {
                                    downded=false;
                                }
                          }
         if(downded)
         query.exec("update ET_CITYPAGES	set	showpic="""+localpath+""" where id="+QString::number(id)+"");

        }
       if(imgsrc100.indexOf("http")>0)
        {
            downded=true;
         localpath=QDir::currentPath()	+ imgsrc100.remove(0,8).replace('/','\\');
         QDir	dir;
         if(!dir.exists(localpath))dir.mkdir(localpath);
         tmplocal=QDir::currentPath() +"TempDown\\"+imgsrc100.remove(0,8).replace('/','\\');
         if(!dir.exists(tmplocal))dir.mkdir(tmplocal);
         QFileInfo info(localpath);
                            if(!info.exists())
                            {
                                downSucc=down.Downfile(tmplocal, (imgsrc100)); //下载文件到临时目录
                                if(downSucc)
                                {
                                             copyFileToPath(tmplocal, localpath, true);
                                }
                                else {
                                    downded=false;
                                }
                          }
         if(downded)
         query.exec("update ET_CITYPAGES	set	imgsrc100="""+localpath+""" where id="+QString::number(id)+"");

        }
       if(imgsrc220.indexOf("http")>0)
        {
            downded=true;
         localpath=QDir::currentPath()	+ imgsrc220.remove(0,8).replace('/','\\');
         QDir	dir;
         if(!dir.exists(localpath))dir.mkdir(localpath);
         tmplocal=QDir::currentPath() +"TempDown\\"+imgsrc220.remove(0,8).replace('/','\\');
         if(!dir.exists(tmplocal))dir.mkdir(tmplocal);
         QFileInfo info(localpath);
                            if(!info.exists())
                            {
                                downSucc=down.Downfile(tmplocal, (imgsrc220)); //下载文件到临时目录
                                if(downSucc)
                                {
                                             copyFileToPath(tmplocal, localpath, true);
                                }
                                else {
                                    downded=false;
                                }
                          }
         if(downded)
         query.exec("update ET_CITYPAGES	set	imgsrc220="""+localpath+""" where id="+QString::number(id)+"");

        }
      }

    }

void ResourceMan::DownFiles(ResourceType resType)
{
   QString resEntry;//
   bool downSucc;
   QString remote, tmpLocal, local,debugmessage;
   QDir tmpLocaldir,localdir;


  for(int i=0;i<fileList.size()-1;i++)
  {
    resEntry=FFileList[i];
    QFileInfo file(resEntry);
    remote=paramMan.RscSrvappendr() + file.fileName(); //得到远程文件的路径
    //得到本地临时文件的路径
    QFileInfo fileRemote(remote);
    tmpLocal =QDir::currentpath() + DownTempDir + fileRemote.fileName();
    QFileInfo fileTmpLocal(tmpLocal);
    tmpLocaldir=fileTmpLocal.absoluteDir();
    if (!tmpLocaldir.exists())
        tmpLocaldir.mkdir(tmpLocal);
    //得到本地文件的保存路径
    local= QDir::currentpath() + file.fileName();
    QFileInfo fileLocal(local);
    if(!fileLocal.exists())
    {
      localdir=fileLocal.absoluteDir();
     if (!localdir.exists())
        localdir.mkdir(local);
      debugmessage= "正在下载:" +fileLocal.fileName();
      SendMessage(frmMain.Handle, MSG_DOWN_RESOURCE, Cardinal(&debugmessage[1]), 0);//往GUI界面窗口输出信息.
      downSucc=down.Downfile(tmpLocal,remote.toLower());//下载文件到临时目录
      if (downSucc)
      {
        copyFileToPath(tmpLocal,local, true);
        if (resType == rtCompany)
        {
          setid(QString::number(resentry.id));//resentry是PResourceEntry.
        }
        else
        {
          if (poststate(QString::number(resentry.id)))//
          {
            debugmessage= "提交状态成功，广告id:" + QString::number(resentry.id);
            SendMessage(frmMain.Handle, MSG_DOWN_RESOURCE, Cardinal(&debugmessage[1]), 0);//往GUI界面窗口输出信息.
            setid(QString::number(resentry.id))
          }
            else
          {
            debugmessage= "提交状态失败，广告id" + QString::number(resentry.id);
            SendMessage(frmMain.Handle, MSG_DOWN_RESOURCE, Cardinal(&debugmessage[1]), 0);//往GUI界面窗口输出信息.
            break;
          }
        }
      }
    } else
    {
      if(!resType=rtCompany)
      {
        if (poststate(QString::number(resentry.id)))
        {
          debugmessage= "提交状态成功，广告id:" + QString::number(resentry.id);
            SendMessage(frmMain.Handle, MSG_DOWN_RESOURCE, Cardinal(&debugmessage[1]), 0);//往GUI界面窗口输出信息.
            setid(QString::number(resentry.id));
        }
        else
        {
          debugmessage= "提交状态失败，广告id" + QString::number(resentry.id);
            SendMessage(frmMain.Handle, MSG_DOWN_RESOURCE, Cardinal(&debugmessage[1]), 0);//往GUI界面窗口输出信息.
            break;
        }
      } else
        setid(QString::number(resentry.id));
        }
      }


}


   void ResourceMan::setid(QString id)
   {
    QString sql;

       //插入数据库
     sql="select count(id) as count from et_attachment_downed where id=" + id;
     QSqlQuery query(FDB);
     query.exec(sql);
     if(!query.size()>0)
     {
       sql="insert into et_attachment_downed (id) values (" + id + ")";
       query.exec(sql);
     }
   }
   bool ResourceMan::poststate(QString id)
   {
    QString res;
    QString downappendress;

    paramList.clear();
    paramList.append("tid=" + paramMan.MachineID);
    paramList.append("attid=" + id);
    downappendress=paramMan.RscSrvappendr() + "/backend/interface/PostTerminalDownedState";
    res=down.DownText(downappendress, paramList);
    return true;
   }

   ResourceMan::ResourceMan()
   {
   }


   void ResourceMan::Execute()
   {
             ResourceType r;

           GetFileList(rtAdver); //广告文件优先
           DownFiles(r);
           GetFileList(rtShuipai);
           DownFiles(r);
           DownDDURLPic();
           DownCityPage();
       //  except
        //   on e:Exception do
         //    raise Exception.Create('ResourceManager:'+e.Message);
        // end;
   }
