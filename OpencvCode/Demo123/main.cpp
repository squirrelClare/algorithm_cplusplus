#include <iostream>
#include<string>

using namespace std;

int main()
{
    int** a;
    a=new int*[1000];
    for (int i=0;i<1000;++i)
    {
        a[i]=new int[1000];
    }

    for (int i=0;i<1000;++i)
    {
        for (int j=0;j<1000;++j)
        {
            a[i][j]=std::rand()%100;
        }
    }

    for (int i=0;i<1000;++i)
    {
        for (int j=0;j<1000;++j)
        {
            std::cout<<a[i][j]<<'\t';
        }
        std::cout<<'\n';
    }
    return 0;
}

