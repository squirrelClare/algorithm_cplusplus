#include <iostream>

using namespace std;

template<int N>
int sum()
{
    return N + sum<N - 1>();
}

template<>
int sum<1>()
{
    return 1;
}

int Sum(int* a,size_t size)
{
    int temp=0;
    std::cout<<sizeof(a)/sizeof(int)<<'\t';
    for(size_t i=0;i<size;++i){
        temp+=a[i];
    }
    return temp;
}
int main()
{
    cout<<sum<100>()<<endl;
    int a[12]={323,34,5665,67};
    std::cout<<sizeof(a)/sizeof(int)<<'\t';
    std::cout<<Sum(a,12);
    system("pause");
    return 0;
}
