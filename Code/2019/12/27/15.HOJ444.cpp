/*************************************************************************
	> File Name: 15.HOJ444.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 16时15分44秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 100
using namespace std;

int num[max_n + 5] = {0};

int main() {
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> num[i];
    cin >> x;
    for (int i = 1; i < x; i++) cout << num[i] << " ";
    cout << num[n] << " ";
    for (int i = x; i <= n - 1; i++) {
        i == n - 1 && cout << num[i];
        i != n - 1 && cout << num[i] << " ";
    }
    return 0;
}
