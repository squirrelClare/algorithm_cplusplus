#include <iostream>
#include<algorithm>
#include<vector>
#include"myclass.h"
using namespace std;

int main()
{
    vector<int> vec({45,67,87,65,46,78,97,46,46,54,89});
    for_each(vec.begin(),vec.end(),[](int n){cout<<n<<'\t';});
    cout<<endl<<*max_element(vec.begin(),vec.end())<<endl;
    for_each(vec.begin(),vec.end(),[](int n){cout<<n%7<<'\t';});

    cout<<endl<<*max_element(vec.begin(),vec.end(),[](int i,int j)
    {
        return (i%7)<(j%7);
    })<<endl;

    cout<<endl<<*min_element(vec.begin(),vec.end(),[](int i,int j)
    {
        return (j%7)>(i%7);
    })<<endl;

    cout<<boolalpha<<all_of(vec.begin(),vec.end(),[](int n)
    {
        return n>40;
    })<<endl;

    cout<<boolalpha<<any_of(vec.cbegin(),vec.cend(),[](int n)
    {
        return n<100;
    })<<endl;

    sort(vec.begin(),vec.end());
    for_each(vec.cbegin(),vec.cend(),[](int n){cout<<n<<'\t';});
    cout<<endl<<lower_bound(vec.cbegin(),vec.cend(),66)-vec.begin()<<endl;
    cout<<upper_bound(vec.cbegin(),vec.cend(),66)-vec.begin()<<endl;
    cout<<boolalpha<<binary_search(vec.begin(),vec.end(),78)<<endl;

    auto re=equal_range(vec.begin(),vec.end(),78);
    cout<<re.first-vec.begin()<<endl<<re.second-vec.begin()<<endl;

    MyClass* my1=new MyClass();
    MyClass* my2=new MyClass(3,"husydua");
    cout<<"my1: "<<my1->value<<'\t'<<my1->str<<endl;
     cout<<"my2: "<<my2->value<<'\t'<<my2->str<<endl;
    MyClass* my3=my1;
    my3=my2;
     cout<<"my1: "<<my1->value<<'\t'<<my1->str<<endl;


     vector<int> vTest(10);
     generate(vTest.begin(),vTest.end(),[](int i){return i;});
    return 0;
}

