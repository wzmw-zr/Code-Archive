/*************************************************************************
	> File Name: 3.final.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月02日 星期日 19时49分49秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>
using namespace std;

class A : public map<int, int> {
public: 
    virtual void say() {
        cout << "Class A : hello world" << endl;
    }
};

class B : public A {
public:
    void say() final {
        cout << "Class B : hello world" << endl;
    }
};

class C : public B {
public:
};

int main() {
    return 0;
}
