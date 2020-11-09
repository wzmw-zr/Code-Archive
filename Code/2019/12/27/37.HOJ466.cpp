/*************************************************************************
	> File Name: 37.HOJ466.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 21时25分24秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
using namespace std;

int is_val(int n) {
    int x = n, res  = 0;
    while (x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res == n;
}

void get_palindrome(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        is_val(i) && (count++);
    }
    cout << count;
}

int main() {
    int n;
    cin >> n;
    get_palindrome(n);
    return 0;
}
