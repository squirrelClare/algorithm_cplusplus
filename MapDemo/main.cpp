#include <iostream>
#include <fstream>
#include <iostream>
#include<istream>
#include "Finder.h"

void Print(const std::set<int>& locs,const std::string& str,const Finder& f);//输出含有指定单词的所有行的具体文本
std::string make_plural(int size,std::string str1,std::string str2);//检测行号是否大于1,从而决定单词是否采用复数形式

int main()
{
    std::string fileName="F:\\CodeBOX\\Qt\\MapDemo\\test.txt";//文件名
    std::ifstream infile;
    infile.open(fileName,std::ios_base::in);//创建一个文件流并打开fileName

    //检测文件是否成功打开
    if (!infile.is_open())
    {
        std::cout<<"Open field!!!"<<std::endl;
        return 0;
    }

//    std::string text;
//    while (std::getline(infile,text));
//    {
//        std::cout<<text<<std::endl;
//    }
//    return 0;

    //实例化一个Finder对象
    Finder f;
    f.ReadFile(infile);//读入文本

    //查询
    while (true)
    {
        std::cout<<"Enter word to look for,or q to quit:";

        //创建一个string存储要查询的单词
        std::string str;
        std::cin>>str;

        //如果输入流cin不能正常工作或者输入的单词为"q",则退出查询
        if (!std::cin|str=="q")
        {
            break;
        }

        std::set<int> locs=f.RunQuery(str);//获取包含要查询的单词str的所有用行号
        Print(locs,str,f);//输出结果
    }
    return 0;
}

void Print( const std::set<int>& locs,const std::string& str,const Finder& f )
{
    int sizeResult=locs.size();//获取集合的大小

    //输出单词出现的次数信息
    //make_plural()决定用"time"还是"times"
    std::cout<<std::endl<<str<<" occurs "<<sizeResult<<" "
        <<make_plural(sizeResult,"time","s")<<std::endl;

    //获取set的开始迭代器
    std::set<int>::const_iterator it=locs.cbegin();
    for (;it!=locs.cend();++it)
    {
        std::cout<<"\t(line"
            <<(*it)+1<<")"<<std::endl<<f.TextLine(*it)//(*it)+1是因为计算机中记录行号是从0开始而不是1
            <<std::endl;
    }
}

std::string make_plural( int size,std::string str1,std::string str2 )
{
    //判断包含指定单词的行数
    if (size>1)
    {
        //行数大于1则返回"times"
        return str1+str2;
    }
    //不大于以则返回"time"
    return str1;
}
