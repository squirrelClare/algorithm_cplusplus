#include <QCoreApplication>
#include"catcher.h"
#include<QDebug>
#include<iostream>
#include"fileopenerror.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Catcher ca;
    QVector<QString> vec;
    try{
        ca.ReadIntegerFile("F:CodeBOX\\Qt\\Math\\BottomUp\\solver.cpp",vec);
        ca.ReadIntegerFile("F:\\CodeBOX\\Qt\\Math\\BottomUp\\solver.cpp",vec);
        ca.ReadIntegerFile("code.txt",vec);
    }catch(const FileOpenError& e){
        std::cerr<<__func__<<":caught exception--"<<"cerr:"<<e.what()<<std::endl;
    }

    //异常处理
    //cout可以把数据放在缓冲区
    //cerr直接把数据输出到屏幕,主要是在紧急情况下输出信息(比如堆栈溢出!!)
    try{
        ca.SafeDivide(23,3);
        ca.SafeDivide(231,2);
    }catch(const std::invalid_argument& e){
        std::cout<<"caught exception--"<<"cout:"<<e.what()<<std::endl;
        std::cerr<<"caught exception--"<<"cerr:"<<e.what()<<std::endl;
    }catch(const QString& str){
        std::cout<<"Caught exception--"<<"cout:"<<str.toStdString()<<std::endl;
        std::cerr<<"Caught exception--"<<"cerr:"<<str.toStdString()<<std::endl;
    }catch(const std::runtime_error& e){
        std::cout<<"Caught exception--"<<"cout:"<<e.what()<<std::endl;
        std::cerr<<"Caught exception--"<<"cerr:"<<e.what()<<std::endl;
    }

    //嵌套异常测试
    //dynamic_cast
    try{
        ca.DoSomething();
    }catch(const MyException& e){//捕获MyException
        std::cout<<__func__<<" :caught MyException:"<<e.what()<<std::endl;
        //抛出被捕获的runtime_error
        const std::nested_exception* pNested=dynamic_cast<const std::nested_exception*>(&e);

        //对抛出的runtime_error重新抛出并获取
        if(pNested){
            try{
                //重新抛出runtime_error
                pNested->rethrow_nested();
            }catch(const std::runtime_error& e){//重新捕获runtime_error
                std::cout<<__func__<<"Nested exception:"<<e.what()<<std::endl;
            }
        }
    }

    //嵌套异常测试
    //rethrow_if_nested
    try{
        ca.DoSomething();
    }catch(const MyException& e){//捕获MyException
        std::cout<<__func__<<" :caught MyException:"<<e.what()<<std::endl;

        try{
            std::rethrow_if_nested(e);
        }catch(const std::runtime_error& e){//重新捕获runtime_error
            std::cout<<__func__<<"Nested exception:"<<e.what()<<std::endl;
        }
    }


    return a.exec();
}
