#include <QCoreApplication>
#include<student.h>
#include<QTextCodec>
#include<grate.h>
#include<school.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
     QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
     QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

     Student *Hstu_1=new Student("李四","ert141",34);
     Student *Hstu_2=new Student("王五","jkl141",23);
     Student *Hstu_3=new Student("小高","kbn131",46);

     Grate *grateTwo=new Grate("grateTwo");
     grateTwo->Add(*Hstu_1);
     grateTwo->Add(*Hstu_2);
     grateTwo->Add(*Hstu_3);



     Student *stu_1=new Student("李明","013141",16);
     Student *stu_2=new Student("小红","026141",35);
     Student *stu_3=new Student("赵欢","015131",27);

     Grate *grateOne=new Grate("grateOne");
     grateOne->Add(*stu_1);
     grateOne->Add(*stu_2);
     grateOne->Add(*stu_3);

  School *xiaoxue=new School("xiaoxue");
    xiaoxue->Add(grateOne->grateName,*grateOne);
     xiaoxue->Add(grateTwo->grateName,*grateTwo);
     xiaoxue->ShowMemeber();
    return a.exec();
}
