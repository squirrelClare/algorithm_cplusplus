#include <QCoreApplication>
#include<QTextStream>
#include<QString>
#include<QTextCodec>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream out(stdout);//设置输出流
    QTextStream in(stdin);//设置输入流

    out<<"Please enter the size of the square:"<<endl;

    int tangleSize=0;//初始化正方形的大小为0
    in>>tangleSize;//从控制台获取正方形的大小

    for(int i=0;i<tangleSize;++i){

        QString str;//初始化一个字符串用以存储每一行的字符

        if(i==0||i==tangleSize-1){//行号为第一行和最后一行的情况
            for(int j=0;j<tangleSize;++j)
                str.append("*");
        }else{//除去第一行和最后一行
            for(int j=0;j<tangleSize;++j){
                if(j==tangleSize-1||j==0)//第一个字符和最后一个字符
                    str.append("*");
                else
                    str.append(" ");//中间空白字符
            }
        }

        out<<str<<endl;//输出每一行,endl表示一行结束,用以构成矩形
    }

    return a.exec();
}
