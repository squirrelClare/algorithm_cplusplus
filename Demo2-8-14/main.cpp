#include <QCoreApplication>
#include<vector>
#include<iostream>
#include<string>
#include<iterator>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<string> vec({"this","is","a","cat"});
    vector<string>vec2(2,"@");
    vec2.insert(vec2.end(),vec.cbegin(),vec.cend());

    for(vector<string>::iterator it=vec2.begin();it!=vec2.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;

    vector<vector<int>>vec3;
    for(int i=0;i<10;++i){
        vector<int> vec(10,i);
        vec3.push_back(vec);
    }
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            cout<<vec3[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"********************************"<<endl<<endl;
    vector<vector<int>*> vec4;
    for(int i=0;i<10;++i){
        vec4.push_back(new vector<int>(10,i));
    }
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            cout<<(*vec4[i])[j]<<" ";
        }
        cout<<endl;
    }
    return a.exec();
}
