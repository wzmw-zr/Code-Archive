/*************************************************************************
	> File Name: 6.money.improve.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 11时13分54秒
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
int num[max_n + 5] = {0};

void solve(int m, int n) {
    for (int i = 1; i <= m; i++) {
        num[0]  = 1;
        for (int j = 1; j <= max_n; j++) {
            if (j >= money[i]) num[j] += num[j - money[i]];
            num[j] %= 9973;
        }
    }
    printf("%d\n", num[n]);
}

int main() {
    int m, n; 
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &money[i]);
    }
    solve(m, n);
    return 0;
}
