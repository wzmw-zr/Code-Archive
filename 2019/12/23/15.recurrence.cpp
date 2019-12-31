/*************************************************************************
	> File Name: 15.recurrence.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 16时51分27秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 10
#define max_k 100000
using namespace std;

int a[max_n + 5] = {0};
int num[max_k + 5] = {0};

void solve(int k, int m) {
    printf("%d", num[k] % m);
}

void init(int m) {
    for (int i = 1; i < 10; i++) num[i] = i;
    for (int i = 10; i <= max_k; i++) {
        for (int j = 1; j <= max_n; j++) {
            num[i] += a[j] * num[i - j];
            num[i] %= m;
        }
    }
}

int main() {
    int k, m;
    scanf("%d%d", &k, &m);
    for (int i = 1; i <= 10; i++) {
        scanf("%d", &a[i]);
    }
    init(m);
    solve(k, m);
    return 0;
}
