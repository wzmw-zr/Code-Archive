/*************************************************************************
	> File Name: 35.HOJ467.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 21时19分56秒
 ************************************************************************/

#include<iostream>
using namespace std;

int fac(int n) {
    if (n == 1) return 1;
    return n * fac(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << fac(n);
    return 0;
}
