/*************************************************************************
	> File Name: 6.virtual_inherit.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月18日 星期二 19时10分59秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<memory>
using namespace std;

struct A {
    int data;
    A(int theData) : data(theData) {}
};

struct B : virtual A {
    B() : A {1} {
        cout << data << endl;
    }
};

struct C : virtual A {
    C() : A{2} {
        cout << data << endl;
    }
};

struct D : B, C {
    D() : A{3} {}
};

int main() {
    D d;
    cout << d.data << endl;
    return 0;
}
