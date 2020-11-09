/*************************************************************************
	> File Name: 38.HOJ465.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 21时29分54秒
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

void digit(long long n, int k) {
    int d = 0, res;
    while (n) {
        d++;
        res = n % 10;
        cout << "res = " << res << endl;
        n /= 10;
        if (d != k) continue;
        cout << res;
        return ;
    }
    cout << 0;
    return ;
}

int main() {
    long long n;
    int k;
    cin >> n >> k;
    digit(n, k);
    return 0;
}
