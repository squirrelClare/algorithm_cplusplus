#include <iostream>
#include<complex>
#include<math.h>
using namespace std;

int main()
{
    complex<double> c(3,4);
    complex<double> b(3,0);
    cout << abs(c) << endl;
    cout << arg(c) << endl;
    cout << conj(c) << endl;
    cout << norm(c) << endl;
    cout << pow(c,2) << endl;
    cout << polar(8.0,M_PI/6) << endl;
    cout<<exp(complex<double>(0,M_PI/3))<< endl;
    cout <<sin(M_PI/3) << endl;\
    cout <<c/b << endl;
    cout << M_PI << endl;
    cout<<exp(complex<double>(0,M_PI/6))<<endl;

    cout <<"**************************" << endl;
    cout <<9.0*c << endl;
    cout <<c*9.0 << endl;
    cout <<c/9.0 << endl;
    cout <<sin(M_PI/6) << endl;
    return 0;
}

