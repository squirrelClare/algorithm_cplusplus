#include <iostream>
#include<random>
#include<iostream>
#include<time.h>
#include<set>
using namespace std;

void generate(int n,int m,int* arr)
{
    int* src=new int[n];
    for(int i=0;i<n;++i)
    {
        src[i]=i+1;
    }
    srand((unsigned)(time(0)));

    int tag=n-1;
    for(int i=0;i<m;++i)
    {
        int index=rand()%(n-i);
        int temp=src[index];
        src[index]=src[tag];
        src[tag--]=temp;
        arr[i]=temp;
    }
}

int main()
{
    int a[2000];
    generate(10000,2000,a);

//    for(int i=0;i<20;++i)
//    {
//        cout<<a[i]<<'\t';
//    }
    set<int>  s(a,a+2000);
    cout<<'\n'<<s.size()<<endl;
    return 0;
}

