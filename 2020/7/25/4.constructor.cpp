/*************************************************************************
	> File Name: 4.constructor.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月25日 星期六 18时22分19秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

struct A {
    int x, y;
    A() {
        cout << "default constructor" << endl;
    }

    A(int n) {
        cout << "one int contructor" << endl;
        x = n, y = n;
    }

    A(const A &b) {
        cout << "copy constructor" << endl;
        this->x = b.x, this->y = b.y;
    }

    void operator=(int n) {
        cout << "operator = " << endl;
        this->x = n, this->y = n;
    }

    void output() {
        cout << this->x << " " << this->y << endl;
    }

    ~A() {}
};

void func(int &x) {
    x += 10;
}

int main() {
    cout << "pre position" << endl;
    A a;
    A b = 6;
    A c(8);
    b = 10;
    A d(b);
    b.output();
    c.output();
    d.output();
    cout << "next position" << endl;
    return 0;
}
