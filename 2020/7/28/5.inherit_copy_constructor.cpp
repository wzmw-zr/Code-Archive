/*************************************************************************
	> File Name: 5.inherit_copy_constructor.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月28日 星期二 20时45分50秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class A {
public:
    A() {
        cout << "class A constructor" << endl;
        this->x = 0x1020304;
    }

    A(const A &a) {
        cout << "class A copy constructor : " << this << endl;
    }
private:
    int x;
};

class B : public A {
public:
    B() { 
        this->y = 0x05060708;
        cout << "class B constructor" << endl;
    }

    B(const B &b) : A(b) {
        cout << "class B copy constructor : " << this << endl;
    }
private:
    int y;
};

int main() {
    B b1;
    B b2(b1);
    const char *msg = (const char *) &b1;
    for (int i = 0; i < sizeof(b1); i++) {
        printf("%X", msg[i]);
    }
    printf("\n");
    return 0;
}
