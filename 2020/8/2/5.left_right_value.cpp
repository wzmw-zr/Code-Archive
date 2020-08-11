/*************************************************************************
	> File Name: 5.left_right_value.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月02日 星期日 20时25分00秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

#define TEST(a, f) {\
    cout << #a << " : " << #f << " ";\
    f(a);\
}

void f2(int &x) {
    cout << "right value" << endl;
}

void f2(int &&x) {
    cout << "right value" << endl;
}

void f(int &x) {
    cout << "left value" << endl;
    TEST(x, f2);
}

void f(int &&x) {
    cout << "right value" << endl;
    TEST(move(x), f2);
    TEST(forward<int &&>(x), f2);
}

int test_func(const int &x) {
    cout << x << endl;
    return 0;
}
 
int main() {
    int a = 123 + 456;
    int b = 1, c = 3;
    f(a);
    f(a++);
    f(++a);
    f(a + b);
    int x = 123;
    test_func(x);
    return 0;
}
