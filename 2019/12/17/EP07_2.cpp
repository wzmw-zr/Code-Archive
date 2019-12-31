/*************************************************************************
	> File Name: EP07_2.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月17日 星期二 10时09分01秒
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
        if (!prime[i]) {
            for (int32_t j = i; j <= MAX_N; j += i) {
                if (!prime[j]) prime[j] = i;
            }
        }
    }
    int32_t n;
    while (~scanf("%d", &n)) {
        printf("%d\n", prime[n]);
    }
    return 0;
}
