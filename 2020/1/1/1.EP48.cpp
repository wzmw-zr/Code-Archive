/*************************************************************************
	> File Name: 1.EP48.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月01日 星期三 09时14分06秒
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
#define mod_num 10000000000
#define max_n 1000
#define DIGS 100000
using namespace std;

long long multiMod(long n, long m) {
    long long a, b, c, d, ans = 0;
    a = n / DIGS, b = n % DIGS, c = m / DIGS, d = m % DIGS;
    ans = ((a * c)) % mod_num;
    ans = (((ans * DIGS) % mod_num) * DIGS) % mod_num;
    ans = (ans + ((a * DIGS) % mod_num) * d) % mod_num;
    ans = (ans + ((b * DIGS) % mod_num) * c) % mod_num;
    ans = (ans + b * d) % mod_num;
    return ans;
}

long long quick_pow(long long n) {
    long long a = 1, b = n, temp = n;
    while (b) {
        //cout << "b & 1 = " << (b & 1) << endl;
        if (b & 1) a = multiMod(a, temp);
        temp = multiMod(temp, temp);
        b >>= 1;
    }
    return a;
}

int main() {
    long long res = 0;
    for (long long i = 1; i <= max_n; i++) {
        long long x = quick_pow(i);
        //cout << "quick_pow(" << i << ") = " << x << endl; 
        res += (x % mod_num);
        res %= mod_num;
    }
    cout << res << endl;
    return 0;
}
