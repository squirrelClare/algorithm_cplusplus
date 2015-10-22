#include <QCoreApplication>
#include<iostream>
#include<string>
#include<
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    //c风格的字符串
    char text1[]="dadasd";
    cout<<sizeof(text1)<<endl<<strlen(text1)<<endl;
    char* text2="dadasd";
    cout<<sizeof(text2)<<endl<<strlen(text2)<<endl;//sizeof返回的是text2的指针的大小,不是字符串的大小
    string s=to_string(213123);
    cout<<s<<endl;
    int sValue=stoi(s);
    cout<<sValue+10<<endl;

    string s1=R"~(djkashdiqw
    dasdhjkash
    skdajdklajnk
    dsajkdjak)~";
    cout<<s1<<endl;
    cout<<sizeof(s1)<<endl<<s1.length();


    regex r("^(\\d{4})/(?:0?[1-9]|1[0-2])/(?:0?[1-9]|[1-2][0-9]|3[0-1])$");
//    regex r("//\\s*(.+)");
    while (true){
        cout<<"Enter a date (year/month/day) (q=quit)"<<endl;
        string str;
        if (!getline(cin,str)||str=="q"){
            break;
        }
        if (regex_match(str,r)){
            cout<<"Valid date !!!!"<<endl;
        }else{
            cout<<"Invalid date !!!"<<endl;
        }
    }
    return a.exec();
}
