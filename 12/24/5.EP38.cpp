/*************************************************************************
	> File Name: 5.EP38.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月24日 星期二 18时22分05秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#define max_n 100000
using namespace std;

int digits(long n) {
    if (n == 0) return 1;
    return floor(log10(n)) + 1;
}


long calc(long x) {
    long n = 1, ans = 0;
    while (digits(ans) < 9) {
        ans *= pow(10, digits(x * n));
        ans += n * x;
        n++;
    }
    if (digits(ans) - 9) return 0;
    int num[10] = {0};
    num[0] = 1;
    long tmp = ans;
    while (tmp) {
        if (num[tmp % 10]) return 0;
        num[tmp % 10]  = 1;
        tmp /= 10;
    }
    return ans;
}



int main() {
    long ans = 0;
    for (long  i = 1; i < max_n; i++) {
        long temp = calc(i);
        if (temp > ans) ans = temp;
    }
    printf("%lld\n", ans);
    return 0;
}
