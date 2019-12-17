/*************************************************************************
	> File Name: EP07_1.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月17日 星期二 09时54分54秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define MAX_N 10000
using namespace std;

int32_t prime[MAX_N + 5] = {0};

int32_t main() {
    for (int32_t i = 2; i <= MAX_N; i++) {
        if (prime[i] == 0) {
            for (int32_t j = 2 * i; j <= MAX_N; j += i) {
                prime[j] = 1;
            }
        }
    }
    int32_t n;
    while (~scanf("%d", &n)) {
        printf("%s", prime[n] == 0 ? "YES" : "NO");
    }
    return 0;
}
