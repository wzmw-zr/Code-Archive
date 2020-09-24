/*************************************************************************
	> File Name: 2.case.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月22日 星期二 21时35分10秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

struct A {
    int real, img;

    A(int real, int img) : real(real), img(img) {}

    struct A operator+(A &b) {
        return {this->real + b.real, this->img + b.img};
    }

    void operator=(const A &b) {
        this->real = b.real;
        this->img = b.img;
    }
};

ostream &operator<<(ostream &out, const A &b) {
    out << b.real << " + " << b.img << "i";
    return out;
}

int main() {
    A a(1, 2);
    A b(4, 2);
    a = b;
    cout << a << endl;
    return 0;
}
