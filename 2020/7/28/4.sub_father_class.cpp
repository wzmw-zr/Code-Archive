/*************************************************************************
	> File Name: 4.sub_father_class.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月28日 星期二 19时56分39秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class D {
public:
    D() { cout << "D constructor" << endl; }
    ~D() { cout << "D destructor" << endl; }
};

class A {
public:
    A() { cout << "A constructor" << endl; }
    A(int x, int y) { cout << "A constructor" << endl; }
    ~A() { cout << "A destructor" << endl; }
};

class B {
public:
    B() { cout << "B constructor" << endl; }
    ~B() { cout << "B destructor" << endl; }
};

class C : public D {
public:
    C() : a(1, 2), b() { cout << "C constructor" << endl; }

    ~C() { cout << "C destructor" << endl; }

private:
    B b;
    A a;
};

int main() {
    C c;
    return 0;
}
