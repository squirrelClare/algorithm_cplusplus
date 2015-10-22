#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{   string s("Hello World!");
    cout << s << endl;
    cout<<s.find("k")<<endl;
    vector<int> v({123,43,5,676,8,90,34,0});
    for_each( v.begin(), v.end(), [] (int val)
    {
        cout << val<<'\n';
    } );

    std::vector<int> v2;
    v2.resize(12);
    int i=1;
    std::generate(v2.begin(),v2.end(),[&]()
    {
        return i++;
    });
    for_each( v2.begin(), v2.end(), [] (int val)
    {
        cout << val<<'\n';
    } );
    function<string(string,string)> fConnect=[](string lhs,string rhs)
    {
        return lhs+rhs;
    };
    function<bool(string,string)> fEqual=[](string lhs,string rhs)
    {
        return lhs==rhs;
    };
    cout<<fConnect("It is ","OK !")<<endl;
    cout<<fEqual("It is ","OK !")<<endl;
    cout<<"******************************"<<endl;

    vector<int> vecA(10,0);
    vector<int> vecB(10,0);
    int tag=2;
    generate(vecA.begin(),vecA.end(),[&]()
    {
        return pow(tag++,2);
    });

    for_each( vecA.begin(), vecA.end(), [] (int val)
    {
        cout << val<<'\n';
    } );

    generate(vecB.begin(),vecB.end(),[&]()
    {
        return sin(static_cast<double>(tag))+tag*3;
    });
    vector<int> vecSum(10,0);
    int sum=20;
    int sumV=std::accumulate(vecA.begin(),vecA.end(),100);
    cout<<sum<<'\t'<<sumV<<endl;
    adjacent_difference(vecA.begin(),vecA.end(),vecSum.begin());
    for_each(vecSum.begin(),vecSum.end(),[](int n)
    {
        std::cout<<n<<'\t';
    });

    auto res=max_element(vecSum.begin(),vecSum.end(),[](int lhs,int rhs)
    {
        return !(lhs>rhs);
    });
    cout<<*res<<endl;
    auto it=adjacent_find(vecSum.begin(),vecSum.end(),[](int lhs,int rhs)->bool{
        return rhs==lhs+2;
    });
    if (it!=vecSum.end())
    {
       cout<<*it<<endl;
    }

    return 0;
}

