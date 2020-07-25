/*************************************************************************
	> File Name: 6.default_delete.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月25日 星期六 21时41分13秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

class T {
public:
    T() = default;
};

class A {
public:
    A() = default;
    A(const A &) = delete;

    void say() {
        cout << "hello world" << endl;
    }

    T t;
};

int main() {
    A a;
    return 0;
}
