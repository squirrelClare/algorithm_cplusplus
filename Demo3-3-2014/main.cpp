#include <iostream>
#include "string"

#include "fstream"

#include "sstream"

using namespace std;


int main()

{


        ifstream in("F:\\CodeBOX\\Qt\\Demo3-3-2014\\test.txt");

        if (!in.is_open())

        {

                cerr << "open file error\n";

                return -1;

        }


        int n=0;
        for( string line; getline(in,line); )

        {

                cout <<++n<<"**"<< line << endl;

        }


        return 0;

}
