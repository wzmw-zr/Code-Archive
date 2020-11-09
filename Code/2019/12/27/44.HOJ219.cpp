/*************************************************************************
	> File Name: 44.HOJ219.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 23时42分21秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 10000
using namespace std;

int num[max_n + 5] = {0};

int cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, l1, r1, l2, r2;
    cin >> n >> l1 >> r1 >> l2 >> r2;
    for (int i = 1; i <= n; i++) cin >> num[i];
    sort(num + l1, num + r1 + 1);
    sort(num + l2, num + r2 + 1, cmp);
    for (int i = 1; i <= n; i++) {
        i == n && cout << num[i];
        i != n && cout << num[i] << " ";
    }
    return 0;
}
