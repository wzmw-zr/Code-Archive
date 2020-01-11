/*************************************************************************
	> File Name: 7.permutation.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月06日 星期一 18时26分10秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#include<ctime>
#define max_n 10
using namespace std;

int fac[max_n + 5] = {0}, num[max_n + 5] = {0}, res[max_n + 5] = {0};

void init() {
    fac[0] = 1, num[0] = 1;
    for (int i = 1; i <= 9; i++) fac[i] = i * fac[i - 1], num[i] = 1;
}

int get_number(int p, int number, int &x) {
    int step = number / fac[p - 1], t;
    x = 1;
    for (t = 0; t <= step; x += (t <= step)){
        t += num[x];
    } 
    num[x] = 0;
    res[6 - p + 1] = x;
    number %= fac[p - 1];
    return number;
}

int main() {
    init();
    num[0] = 0, num[1] = 0, num[5] = 0;
    int n;
    cin >> n;
    n--;
    for (int i = 6; i > 0; i--) {
        int x;
        n = get_number(i, n, x);
    }
    for (int i = 1; i <= 6; i++) cout << res[i];
    cout << endl;
    return 0;
}
