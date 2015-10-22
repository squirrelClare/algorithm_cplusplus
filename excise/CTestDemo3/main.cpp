﻿#include <iostream>

double factorial(double n) {
    double ans = 1;
    for (double i = 2; i <= n; ++i) {
        ans = ans * i;
        if (ans < 0) {
            return -1;
        }
    }
    return ans;
}

int main() {
    using namespace std;
    cout << "Please enter n: " << flush;
    double n;
    cin >> n;

    if (n >= 0) {
        double nfact = factorial(n);
        if (nfact < 0) {
            cerr << "overflow error: "
                 << n << " is too big." << endl;
        }
        else {
            cout << "factorial(" << n << ") = "
                 << nfact << endl;
        }
    }
    else {
        cerr << "Undefined:  "
             << "factorial of a negative number: " << n << endl;
    }
    return 0;
}
