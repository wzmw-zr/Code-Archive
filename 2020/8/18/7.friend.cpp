/*************************************************************************
	> File Name: 7.friend.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月18日 星期二 19时18分55秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<memory>
using namespace std;

struct B;
extern void F(B *b);

struct B {
    struct A {
    };
    friend void F(B *b);
private:
    int data;
};

void F(B *b) {
    cout << b->data << endl;
}

int main() {
    B b;
    F(&b);
    return 0;
}
