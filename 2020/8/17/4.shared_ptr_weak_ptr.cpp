/*************************************************************************
	> File Name: 4.shared_ptr_weak_ptr.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月17日 星期一 15时25分24秒
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
    //auto x = make_shared<A>("A");
    shared_ptr<A> x = make_shared<A>("A");
    cout << x->name << endl;
    {
        auto y = x;
        cout << y->name << endl;
    }
    weak_ptr<A> w = x;
    {
        auto y = w.lock();
        cout << x->name << endl;
    }
    x = nullptr;
    {
        auto y = w.lock();
        if (y) cout << "w is not null" << endl;
        else cout << "w is null" << endl;
    }
    return 0;
}
