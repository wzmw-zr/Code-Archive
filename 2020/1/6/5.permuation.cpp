/*************************************************************************
	> File Name: 5.permuation.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月06日 星期一 14时20分09秒
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
using namespace std;

int num[15] = {0}, used[15] = {0}, fac[15] = {0};

void init() {
    fac[0] = 1, fac[1] = 1;
    num[0] = 1, used[0] = 1;
    for (int i = 2; i <= 9; i++) fac[i] = i * fac[i - 1];
    for (int i = 1; i <= 9; i++) num[i] = i, used[i] = 1;
}

int get_num(int k, int n, int &x) {
    int step = k / x, t;
    x = 0;
    for (t = 0; t <= step; x += (t <= step)) t += used[x];
    k %= n;
    used[x] = 0;
    return k;
}

int main() {
    init();
    int n;
    cin >> n;
    n--;
    for (int i = 1; i <= 9; i++) {
        int number = n / fac[9 - i + 1], t, x = 0;
        for (t = 1; t <= number; x+=(t <= number)) t += used[x];
        n %= fac[9 - i + 1];
        used[x] = 0;
        num[i] = x;
    }
    for (int i = 1; i <= 9; i++) cout << num[i];
    cout << endl;
    return 0;
}
