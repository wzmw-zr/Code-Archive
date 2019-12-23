/*************************************************************************
	> File Name: 1.rabbit.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 00时46分44秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_d 50
#define max_n 100
using namespace std;

int num[max_n + 5][max_d + 5] = {0};

void get_val(int n) {
    num[1][0] = 1, num[2][0] = 1;
    num[1][1] = 1, num[2][1] = 2;
    for (int i = 3; i <= n; i++) {
        num[i][0] = num[i - 1][0];
        for (int j = 1;j <= num[i - 2][0]; j++) {
            num[i][j] = num[i - 1][j] + num[i - 2][j];
        }
        for (int j = num[i - 2][0] + 1; j <= num[i - 1][0]; j++) {
            num[i][j] = num[i - 1][j];
        }
        for (int j = 1; j <= num[i][0]; j++) {
            if (num[i][j] < 10) continue;
            num[i][j + 1] += num[i][j] / 10;
            num[i][j] %= 10;
            num[i][0] += (j == num[i][0]);
        }
    }
    for (int i = num[n][0]; i >= 1; i--) {
        printf("%d", num[n][i]);
    }
    printf("\n");
}


int main() {
    int n; 
    scanf("%d", &n);
    get_val(n);
    return 0;
}
