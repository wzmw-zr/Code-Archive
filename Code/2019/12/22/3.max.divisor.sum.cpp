/*************************************************************************
	> File Name: 3.max.divisor.sum.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月22日 星期日 22时57分40秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 1000000
using namespace std;

int prime[max_n + 5] = {0};
long divs_sum[max_n + 5] = {0};

void init() {
    for (long i = 1; i <= max_n; i++) {
        for (long j = i; j <= max_n && i * j <= max_n; j++) {
            //printf("i = %lld, j = %lld\n", i, j);
            if (i == j) divs_sum[i * j] += i;
            divs_sum[i * j] += i + j;
        }
    }
}

int main() {
    init();
    int max = 0;
    for (int i = 1; i <= max_n; i++) {
        if (max >= divs_sum[i]) continue;
        max = divs_sum[i];
    }
    printf("%d", max);
    return 0;
}
