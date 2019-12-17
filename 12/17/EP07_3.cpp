/*************************************************************************
	> File Name: EP07_3.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月17日 星期二 10时18分23秒
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
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            for (int j = i; j <= MAX_N; j += i) {
                prime[j] = i;
            }
        }
    }
    int32_t n;
    while (~scanf("%d", &n)) {
        printf("%d\n", prime[n]);
    }
}
