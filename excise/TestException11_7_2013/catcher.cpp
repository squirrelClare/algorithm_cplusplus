#include "catcher.h"
using namespace std;
Catcher::Catcher()
{
}

Catcher::~Catcher()
{

}

void Catcher::ReadIntegerFile(const QString &fileName, QVector<QString> &dest)
{
    QFile f(fileName);
    if (!f.open(QIODevice::ReadWrite|QIODevice::Text)){
        throw FileOpenError(fileName.toStdString());
    }

    QTextStream out(&f);
    do{
        dest.push_back(out.readLine());
    }while(!out.readLine().isNull());
    f.close();
}

int Catcher::SafeDivide(const int num, int const den)
{//测试抛出三种异常
    if (den==0){
        throw invalid_argument("Divide by zero!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    }
    if(den==2){
        throw QString("the den is 2!!!!!");
    }
    if(den==1){
        throw std::runtime_error("running erroring!!!");
    }
    return static_cast<int>(num/den);
}

//测试嵌套异常
void Catcher::DoSomething() const
{
    try{
        throw std::runtime_error("throwing a runtime_error exception!");
    }catch(const std::runtime_error& e){
        std::cerr<<__func__<<" :caught a runtime_error"<<std::endl;
        std::cerr<<__func__<<" :throwing MyException"<<std::endl;
        //将runtiem_error放到MyException中一起抛出去,MyException已经从nested_exception中集成了嵌套所必须的函数
        std::throw_with_nested(MyException("MyException with nested runtime_error"));
    }
}
