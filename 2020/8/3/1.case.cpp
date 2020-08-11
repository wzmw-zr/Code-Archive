/*************************************************************************
	> File Name: 1.case.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月03日 星期一 16时40分37秒
 ************************************************************************/

#include<iostream>
using namespace std;

void func(int &x) {
    cout << "left_value : " << x << endl;
}

void func(int &&x) {
    cout << "right_value : " << x << endl;
}

int main() {
    int n = 123, &x = n;
    int &&y = 4;
    func(x);
    func(forward<int &>(x));
    func(forward<int &>(y));
    func(forward<int &&>(x));
    func(forward<int &&>(y));
    func(forward<int>(x));
    func(forward<int>(y));
    return 0;
}
