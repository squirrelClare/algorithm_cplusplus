#include <iostream>
#include<time.h>
#include<math.h>
#include<random>
#define  INR 1213123
#define INCER 1
using namespace std;
static unsigned  int seed;
void RandomSeed(int d){
    if (d==0){
        seed=time(0);
    }else{
        seed=d;
    }
}

int Random(int low,int high){
    seed=INR*seed+INCER;
    return (seed%(high-low)+low);
}

int main()
{
    srand((unsigned)time(0));
    for(int i=0;i<100;++i){
        cout<<rand()%100<<endl;
    }
    cout<<Random(1,54)<<endl;
    cout << "Hello World!" << endl;
    return 0;
}

