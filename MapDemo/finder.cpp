#include "finder.h"

Finder::Finder()
{
}

Finder::~Finder()
{

}

void Finder::ReadFile( std::ifstream& is )
{
    //读入文本
    StoreFile(is);
    BuildMap();
}

void Finder::StoreFile( std::ifstream& inStream )
{
    std::string text=" ";
    //检查文件流是否正常工作
    if (!inStream)
    {
        std::cout<<"Error!!"<<std::endl;
        return ;
    }

    //下面代码为书中代码,执行后只能读取最后一行文本
//    while (std::getline(inStream,text,'\n'));
//    {
//        //std::cout<<text<<std::endl;
//        lineOfText.push_back(text);
//    }

    //修改后的代码
    //逐行读取每一行文本并存入lineOfText中
    for (;std::getline(inStream,text);)
    {
        lineOfText.push_back(text);
    }
}

void Finder::BuildMap()
{
    //对每一行文本进行遍历操作
    for (int i=0;i!=lineOfText.size();++i)
    {
        //i为行号
        std::istringstream lineValue(lineOfText.at(i));//第i行文本存入lineValue中
        std::string word;
        while (lineValue>>word)//ineValue为istringstream,该流的特性可以将单词逐个读入word中
        {
            wordMap[word].insert(i);//wordMap[word]是以word为key所对应的value,而该value为一个std::set<int>,set的特性决定同一个单词
                                                  //在一行中即使出现多次,set中也只会记录一次
        }
    }
}

std::set<int> Finder::RunQuery( const std::string& str ) const
{
    //返回wordMap中指定单词所对应的迭代器
    std::map<std::string,std::set<int>>::const_iterator loc
        =wordMap.find(str);

    //检测所查询的单词是否存在于文本中
    if (loc==wordMap.cend())
    {
        //不存在则返回一个空的set
        return std::set<int>();
    }
    else
    {
        //不为空则返回改单词所对应的set
        return loc->second;
    }

}

std::string Finder::TextLine( int lineIndex ) const
{
    //检测行号lineIndex是否越界,即是否超过文本的最大行数
    if (lineIndex<lineOfText.size())
    {
        return lineOfText.at(lineIndex);
    }
    return NULL;
}
