#include <iostream>
#include<vector>
#include<fstream>
#include<istream>
#include<sstream>
#include<string>
#include<tchar.h>
int main()
{
    std::vector<int> vec(10000,0);

    std::string fileName="E:\\CodeBOX\\Qt\\Sort\\test.cpp";

    std::ifstream infile;
    infile.open(fileName,std::ios_base::in|std::ios_base::out);

    if (!infile){
        std::cout<<"Open faield!!"<<std::endl;
        return 0;
    }

//    std::string strTemp=std::string("432 4 7 29 85 69 6 648 435 943 126 31 783 68 175 487 54 284 ")+
//            std::string("92 78 169 8361 371 853 215 381 7537 63 721 8453 8232 985 787 1775 ")+
//            std::string(" 5312 53 781 53 81 253 871 253 7812 ")+
//            std::string("548 17 53 81 7 237 518 390 3475 31 2378 215 835 187 ")+
//            std::string("423 98 65 34 96 5 89 7 48 6 496 498 6 484 ")+
//            std::string("31 29 63 836 49 85 6");
//    std::cout<<"Before sort::"<<std::endl;
//    std::cout<<strTemp<<std::endl;
//    int num;
//    std::istringstream strIN(strTemp);
//    while (strIN>>num){
//            vec.at(num)=1;
//        }
    std::string str;
    int num;
    while (std::getline(infile,str)){
        std::istringstream strIn(str);
        while (strIn>>num)
            vec.at(num)=1;
    }

    std::cout<<std::endl<<"The vector is :"<<std::endl;

    for (int index=0;index<vec.size();++index){
        if (vec.at(index)!=0){
            std::cout<<index<<'\t';
        }
    }

    std::cout<<std::endl;
//    double v1=50;
//    double v2=3;
//    std::cout<<v1/v2;
    return 0;

}


