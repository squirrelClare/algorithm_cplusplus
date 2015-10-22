#include <assert.h>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    using namespace std;
    int i=0;
    char array1[34] = "This is a dreaded C array of char";
    char array2[] = "if not for main, we could avoid it entirely.";
    char *charp = array1;
    string stlstring = "This is an Standard Library string. Muchpreferred." ;
    assert (sizeof(i) == sizeof(int));
    cout << "sizeof char = " << sizeof(char) << '\n';
    cout << "sizeof wchar_t = " << sizeof(wchar_t) << '\n';
    cout << "sizeof int = " << sizeof(int) << '\n';
    cout << "sizeof long = " << sizeof(long) << '\n';
    cout << "sizeof float = " << sizeof(float) << '\n';
    cout << "sizeof double = " << sizeof(double) << '\n';
    cout << "sizeof double* = " << sizeof(double*) << '\n';
    cout << "sizeof array1 = " << sizeof(array1) << '\n';
    cout << "sizeof array2 = " << sizeof(array2) << '\n';
    cout << "sizeof stlstring = " << sizeof(stlstring) << endl;
    cout << "length of stlstring= " << stlstring.length() << endl<<stlstring.size()<<endl;
    cout << "sizeof char* = " << sizeof(charp) << endl;
    return 0;
}
