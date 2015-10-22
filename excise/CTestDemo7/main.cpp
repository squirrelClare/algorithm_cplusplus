#include <iostream>
using namespace std;

int main() {
    int m1(11), m2(13);
    const int* n1(&m1);
    int* const n2(&m2);
    // First snapshot
    cout << "n1 = " << n1 << '\t' << *n1 << '\n'
         << "n2 = " << n2 << '\t' << *n2 << endl;
    cout<<"m1="<<m1<<endl;
    n1 = &m2;
    //*n1 = 15;         <-- 1
    m1 = 17;
    //n2 = &m1;         <-- 3
    *n2 = 16;
    // Second snapshot

     cout<<"m1="<<m1<<endl;
    cout << "n1 = " << n1 << '\t' << *n1 << '\n'
         << "n2 = " << n2 << '\t' << *n2 << endl;
    return 0;
}

