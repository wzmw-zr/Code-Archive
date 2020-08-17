/*************************************************************************
	> File Name: 3.unique_ptr.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月17日 星期一 15时12分09秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<memory>
using namespace std;

class A {
public:
    string name;
    
    A(const string &theName) 
    : name{ theName } {}
};

int main() {
    auto x = make_unique<A>("A");
    cout << typeid(x).name() << endl;
    cout << x->name << endl;

    unique_ptr<A> y(x.release());
    
    if (x) cout << "x is not null" << endl;
    else cout << "x is null" << endl;

    cout << y->name << endl;
    return 0;
}
