#include <iostream>

#include <string>

using namespace std;

#include "decnum.h"



int main()

{

    decnum x, y, r;

    string line;

    size_t  n = 0;

    cout << "input x:" << endl;

    getline(cin,line);

    x = decnum(line.c_str(), line.length());

    cout << "input y:" << endl;

    getline(cin,line);

    y = decnum(line.c_str(), line.length());

    cout << "x = " << x << endl;

    cout << "y = " << y << endl;

    cout << "x * y =" << x * y << endl;

    cout << "x / y =" << x / y << endl;

    cout << "x % y =" << x % y << endl;

    cout << "div(x, y) =" << div(x , y, r) << endl;

    cout << "mod(x, y) =" << r << endl;

    cout << "y ^ 2 =" << pow(y, 2) << endl;

    cout << "x ^ 1/2 =" << root(x, 2) << endl;

    cout << "x is pow = " << x.ispow() << endl;

    system("pause");

    return 0;

}
