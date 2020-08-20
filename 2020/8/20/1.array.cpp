/*************************************************************************
	> File Name: 1.array.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月20日 星期四 09时25分15秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
protected:
    int x;
public:
    A() {
        x = rand() % 100;
        cout << this << " init x value : " << x << endl;
    }
};

struct B : public A {
public : 
    int y;
    void show() {
        cout << this->x << " " << this->y << endl;
    }
    void say(B &b) {
        cout << &b << " " << (static_cast<A&>(b)).x << endl;
    }
};

int main() {
    B b1, b2;
    b1.say(b2);
    return 0;
}
