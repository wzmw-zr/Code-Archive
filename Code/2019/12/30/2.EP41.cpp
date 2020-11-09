/*************************************************************************
	> File Name: 2.EP41.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月30日 星期一 20时45分31秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
using namespace std;

int is_prime(long n) {
    for (long i = 2; i <= (long) sqrt(n); i++) {
        if (n % i) continue;
        return 0;
    }
    return 1;
}

int is_pandigital(long n) {
    long digit = floor(log10(n)) + 1;
    long num[10] = {0};
    num[0] = 1;
    while (n) {
        if (num[n % 10]) return 0;
        num[n % 10] = 1;
        n /= 10;
    }
    for (long i = 1; i <= digit; i++) {
        if (num[i]) continue;
        return 0;
    }
    return 1;
}

int main() {
    long ans = 0;
    for (long i = 1; i <= 987654321; i++) {
        if (is_prime(i) && is_pandigital(i)) {
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
