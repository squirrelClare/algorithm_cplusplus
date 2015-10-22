#include <iostream>

using namespace std;

int main()
{
//     int a = 1;
//    const int c = 2;
//    const int* p1 = &c;    // OK
//    const int* p2 = &a;    // OK
//    cout<<*p1<<endl;
//    p1=&a;
//        cout<<*p1<<endl;
//        int* const p3=&a;
//          cout<<p3<<*p3<<endl;
//        int d=89;
//        *p3=d;
//      cout<<p3<<*p3<<endl;
////    int* p3;
////    p3= &a;          // error
////    cout<<*p3<<endl;
////    *p3 = 5;               // error
////cout<<*p3<<endl;
////int* p4=&a;
////cout<<*p4;
////int d=c;


    int n=1000;
    int& rn = n;
    cout<<"n="<<n<<endl<<"rn="<<rn<<endl;
    cout<<"&n="<<&n<<endl<<"&rn="<<&rn<<endl;
    return 0;
}

