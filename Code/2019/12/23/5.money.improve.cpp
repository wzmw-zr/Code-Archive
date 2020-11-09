/*************************************************************************
	> File Name: 5.money.improve.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 10时56分54秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_m 20
#define max_n 10000
using namespace std;

int money[max_m + 5] = {0};
int num[2][max_n + 5] = {0};

void solve(int m, int n) {
    num[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        num[i % 2][0] = 1;
        for (int j = 1; j <= max_n; j++) {
            //num[i % 2][j] = 0;
            num[i % 2][j] = num[(i - 1) % 2][j];
            num[i % 2][j] %= 9973;
            if (j >= money[i]) {
                num[i % 2][j] += num[i % 2][j - money[i]];
                num[i % 2][j] %= 9973;
            } 
        }
    }
    printf("%d\n", num[m % 2][n]);
}


int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    money[0] = m;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &money[i]);
    }
    solve(m, n);
    return 0;
}
