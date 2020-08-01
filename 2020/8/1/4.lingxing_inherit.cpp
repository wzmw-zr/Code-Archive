/*************************************************************************
	> File Name: 4.lingxing_inherit.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月01日 星期六 15时14分18秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct A {
    int x;
};

struct B : virtual public A {
    void set(int x) {
        cout << &this->x << endl;
        this->x = x;
    }
};

struct C : virtual public A {
    int get() {
        cout << &this->x << endl;
        return this->x;
    }
};

struct D : public B, public C {

};

int main() {
    D d;
    cout << sizeof(d) << endl;
    d.set(9973);
    cout << d.get() << endl;
    return 0;
}
