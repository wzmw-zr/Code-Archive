/*************************************************************************
	> File Name: 3.bind.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月13日 星期四 11时18分42秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<functional>
using namespace std;

int add(int a, int b) {
    cout << a << " " << b << endl;
    return a + b;
}

int add2(int a, int b, int c) {
    cout << a << " " << b << " " << c << endl;
    return a + b + c;
}

int add_cnt(function<int(int, int)> func, int &n, int a, int b)  {
    n += 1;
    return func(a, b);
}

int main() {
    function<int(int)> f = bind(add, 5, placeholders::_1);
    cout << f(3) << endl;
    cout << f(4) << endl;
    cout << f(5) << endl;
    function<int(int, int)> f_1 = bind(add, placeholders::_2, placeholders::_1);
    int n = 0;
    function<int(int, int)> f5 = bind(add_cnt, add, ref(n), placeholders::_1, placeholders::_2);
    f5(99, 88);
    f5(92, 80);
    f5(95, 78);
    cout << n << endl;
    return 0;
}
