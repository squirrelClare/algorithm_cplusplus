#include <QCoreApplication>
#include<QDebug>
#include<initializer_list>
#include"iostream"
using namespace std;
auto MakeSum(initializer_list<int> lst)->int{//1.可选函数语法;2.初始化列表
    int total={45};
    for(auto iter=lst.begin();iter!=lst.end();++iter){//迭代器
        total+=*iter;
    }
    return total;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int value=434;
    int&& value1=std::move(value);//右值引用
//    value1=434;
    qDebug()<<value1;


    QVector<int> *vector=new QVector<int>();
    for(int i=0;i<101;++i){
        vector->push_back(i*i);
    }
    for(auto value:*vector){
        qDebug()<<value;
    }

    int arry[19]={0};
//    for(auto value:arry){
//        value=123;
//    }
    for(auto value:arry){
        qDebug()<<value;
    }
    /*const*/ int* /*const*/ arry2=new int[12];
    arry2[0]=45;
    arry2=new int[123];
    cout<<MakeSum({7,38,12,7,98,41,6,41,6,31})<<endl;
    return a.exec();
}
