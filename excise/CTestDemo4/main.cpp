#include <iostream>
#include<string>
using namespace std;
int main() {
    using namespace std;
    const char* charstr = "this is one very long string "
             "so I will continue it on the next line";
    string str = charstr;
    cout<< str.size()<<endl;
    cout << str << endl;
    cout << "\nA\tb\\c\'d\"" << endl;
    return 0;
}


