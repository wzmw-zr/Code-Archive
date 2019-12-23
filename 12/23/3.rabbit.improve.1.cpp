/*************************************************************************
	> File Name: 3.rabbit.improve.1.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 09时08分11秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_l 50
using namespace std;

int num[2][max_l + 5] = {0};

void solve(int n) {
    num[1][0] = 1, num[1][1] = 1;
    num[0][0] = 1, num[0][1] = 2;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= num[(i - 2) % 2][0]; j++) {
            num[i % 2][j] = num[(i - 1) % 2][j] + num[(i - 2) % 2][j];
        }
        for (int j = num[(i - 2) % 2][0] + 1; j <= num[(i - 1) % 2][0]; j++) {
            num[i % 2][j] = num[(i - 1) % 2][j];
        }
        num[i % 2][0] = num[(i - 1) % 2][0];
        for (int j = 1; j <= num[i % 2][0]; j++) {
            if (num[i % 2][j] < 10) continue;
            num[i % 2][j + 1] += num[i % 2][j] / 10;
            num[i % 2][j] %= 10;
            num[i % 2][0] += (j == num[i % 2][0]);
        }
    }
    for (int i = num[n % 2][0]; i >= 1; i--) {
        printf("%d", num[n % 2][i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    solve(n);
    return 0;
}
