#include <QCoreApplication>
#include<QDebug>

void Sort(int *arry, int size);
void Sort1(int *arry, int size);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int arry[9]={1200,47,28,46,13,617,845,67,88};
    Sort1(arry,9);
    for(int i=0;i<9;++i)
        qDebug()<<arry[i];

    
    return a.exec();
}


void Sort(int *arry, int size)
{
    for(int j=1;j<size;++j){
        int trans=arry[j];
        int i;
        for(i=j-1;i>-1;--i){
            if(arry[i]>trans)
                arry[i+1]=arry[i];
            else
                break;
        }
        arry[i+1]=trans;
    }
}
void Sort1(int *arry, int size)
{
    for(int j=1;j<size;++j){
        int trans=arry[j];
        //若果i>-1则无法为arry[0]赋值,因为i+1=0不成立
        for(int i=j-1;i>=-1;--i){
            if(arry[i]>trans&&i>-1){
                arry[i+1]=arry[i];
            }
            else{
                arry[i+1]=trans;
                break;
            }
        }
    }
}
