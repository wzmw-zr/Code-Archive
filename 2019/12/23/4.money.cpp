/*************************************************************************
	> File Name: 4.money.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 10时32分08秒
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
int num[max_m + 5][max_n + 5] = {0};


void solve(int m, int n) {
    for (int i = 1; i <= max_n; i++) num[0][i] = 0;
    for (int i = 0; i <= max_m; i++) num[i][0] = 1;
    for (int i = 1; i <= max_m; i++) {
        for (int j = 1; j <= max_n; j++) {
            num[i][j] += num[i - 1][j];
            num[i][j] %= 9973;
            if (j >= money[i]) {
                num[i][j] += num[i][j - money[i]];
                num[i][j] %= 9973;
            }
        }
    }
    printf("%d\n", num[m][n]);
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
