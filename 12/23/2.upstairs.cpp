/*************************************************************************
	> File Name: 2.upstairs.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月23日 星期一 08时54分58秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_s 1500
#define max_n 500
using namespace std;

int solution[max_n + 5][max_s + 5] = {0};

void solve(int n) {
    solution[1][0] = 1, solution[2][0] = 1, solution[3][0] = 1;
    solution[2][1] = 1, solution[3][1] = 1;
    for (int i = 4; i <= n; i++) {
        solution[i][0] = solution[i - 2][0];
        for (int j = 1; j <= solution[i - 3][0]; j++) {
            solution[i][j] += solution[i - 2][j] + solution[i - 3][j];
        }
        for (int j = solution[i - 3][0] + 1; j <= solution[i - 2][0]; j++) {
            solution[i][j] += solution[i - 2][j];
        }
        for (int j = 1; j <= solution[i][0]; j++) {
            if (solution[i][j] < 10) continue;
            solution[i][j + 1] += solution[i][j] / 10;
            solution[i][j] %= 10;
            solution[i][0] += (j == solution[i][0]);
        }
    }
    for (int i = solution[n][0]; i >= 1; i--) {
        printf("%d", solution[n][i]);
    }
    printf("\n");
}


int main() {
    int n;
    scanf("%d", &n);
    solve(n);
    return 0;
}
