#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <string>
#include <QDebug>
 using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string str="cat.";
    vector<string> ivec(1,str);
    vector<int> ivec1(10,3);
    vector<int> ivec2(10);
    vector<string> ivec3(0);

    string str_1[3]={"Yes,","it","is"};
    string str_2[5]={"Is","this","a","cat","?"};

   // ivec.push_back("a");
    ivec.insert(ivec.begin(),"a");
    for(vector<string>::iterator point=ivec.begin();point!=ivec.end();++point){
        cout<<*point<<"  ";
    }
    cout<<endl;
    cout<<"**************************"<<endl;


    for(size_t i=0;i<ivec1.size();++i){
        cout<<ivec1[i]<<"  ";
    }
    cout<<endl;
    cout<<"***************************"<<endl;


    for(size_t i=0;i<ivec1.size();++i){
        cout<<ivec1.at(i)<<"  ";
    }
    cout<<endl;
    cout<<"***************************"<<endl;


    for(size_t i=0;i!=ivec2.size();++i){
        ivec2.assign(10,5);
        cout<<ivec2[i]<<"  ";
    }
    cout<<endl;
    cout<<"****************************"<<endl;


    for(size_t i=0;i!=5;++i){
        ivec3.assign(str_2,str_2+5);
        cout<<ivec3.at(i)<<" ";
    }
    cout<<endl;
    cout<<"****************************"<<endl;


    ivec.insert(ivec.begin(),str_1,str_1+3);
    for(vector<string>::iterator point=ivec.begin();point!=ivec.end();++point){
        cout<<*point<<" ";
    }
    cout<<endl;





    return a.exec();
}
