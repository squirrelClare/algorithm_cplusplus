#include <iostream>

using namespace std;
int F(int n);
void Format(int n);

int main()
{
    Format(20);
    return 0;
}


int F(int n)
{
    if(n==1||n==2)
        return 1;
     else
        return F(n-1)+F(n-2);
}


void Format(int n)
{
    int A[n];
    for(int i=0;i<n;i++){
        A[i]=F(i+1);
        cout<<A[i]<<'\n';
    }
}
