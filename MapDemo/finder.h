#ifndef FINDER_H
#define FINDER_H

#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <sstream>

class Finder
{
public:
    Finder();
    ~Finder();
    std::string TextLine(int lineIndex)const;//输出指定行的文本
    std::set<int> RunQuery(const std::string& str)const;//查询指定单词
    void ReadFile(std::ifstream& is);//读入文本文件
private:
    void StoreFile(std::ifstream& inStream);//将文本每一行存入lineOfText
    void BuildMap();//构建"单词","行数"对应表

    std::vector<std::string> lineOfText;//存储文本,元素为一行文本
    std::map<std::string,std::set<int>> wordMap;//单词,行数对应表

};

#endif // FINDER_H
