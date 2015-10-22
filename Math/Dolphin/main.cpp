#include <iostream>

using namespace std;
void Dolphin(int *array,int n,int k);
int main()
{
    int *array;
    int A[10]={68,2,6,3,48,26,49,6,31,875};
    array=A;
    Dolphin(array,10,4);
    return 0;
}

void Dolphin(int *array, int n, int k)
{
    int d;
    int x;
    k=k%n;
    if(k==0)return;
    d=2;
    for(int i=1;i<=d;i++){
        x=array[n-i];
        for(int j=n-i-k;j!=n-i;j=(n+j-k)%n)
            array[(j+k)%n]=array[j];
        array[(n-i+k)%n]=x;
    }
    for(int i=0;i<10;i++)
        cout<<array[i]<<"***";
}
