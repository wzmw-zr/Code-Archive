/*************************************************************************
	> File Name: 4.class_memner_ptr.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月18日 星期二 15时28分21秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<memory>
using namespace std;

struct X {
    virtual void Print() const {
        cout << "X" << endl;
    }
};

struct Y : public X {
    void Print() const override {
        cout << "Y" << endl;
    }
};

int main() {
    const X &x = Y{};
    x.X::Print();
    (x.*&X::Print)();
    void (X::* print)()const = &X::Print;
    (x.*print)();
    return 0;
}
