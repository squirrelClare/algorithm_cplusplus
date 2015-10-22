#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;


int Charge(int y)
{
    vector<int> z(y+1,0);
    int x[7]={1,2,5,10,20,50,100};
    for (int i=0;i<=y;++i)
    {
        if(count_if(x,x+7,[&](int j){return i==j;})>0)
        {
            z[i]=1;
        }
        else
        {
            z[i]=0;
        }
    }


   for (int i=1;i<=y;++i)
   {
           vector<int> temp;
           for (int j=0;j<=i/2+1;++j)
           {
               if((z[i-j]+z[j])!=0)
                     temp.push_back(z[i-j]+z[j]);
           }
           z[i]=*min_element(temp.begin(),temp.end());
      }
       return z[y];
}

int main()
{
    cout << "Hello World!" << endl;
    cout<<Charge(991)<<endl;
    return 0;
}

