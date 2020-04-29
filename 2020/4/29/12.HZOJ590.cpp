/*************************************************************************
	> File Name: 12.HZOJ590.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月29日 星期三 20时24分45秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
#define MAX_N 1000
#define MAX_M 500000

int n, m;
int num[MAX_N + 5][MAX_N + 5];
int up[MAX_N + 5][MAX_N + 5], down[MAX_N + 5][MAX_N + 5];
int mmax[MAX_N + 5], mmax_ind[MAX_N + 5], mmax2[MAX_N + 5];
int x, y;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) scanf("%d", &num[i][j]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            down[i][j] = max(down[i - 1][j - 1], down[i - 1][j]) + num[i][j];
        }
    }
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            up[i][j] = max(up[i + 1][j + 1], up[i + 1][j]) + num[i][j];
        }
    }
    for (int i = 2; i <= n; i++) {
        int ind1 = 0, ind1_max = 0, ind2_max = 0;
        for (int j = 1; j <= i; j++) {
            int t = down[i][j] + up[i][j] - num[i][j];
            if (t > ind1_max) {
                ind1_max = t;
                ind1 = j;
            }
        }
        for (int j = 1; j <= i; j++) {
            int t = down[i][j] + up[i][j] - num[i][j];
            if (t > ind2_max && j != ind1) {
                ind2_max = t;
            }
        }
        mmax[i] = ind1_max;
        mmax_ind[i] = ind1;
        mmax2[i] = ind2_max;
    }
    while (m--) {
        scanf("%d%d", &x, &y);
        if (x == 1 && y == 1) {
            printf("-1\n");
            continue;
        }
        if (mmax_ind[x] == y) {
            printf("%d\n", mmax2[x]);
        } else {
            printf("%d\n", mmax[x]);
        }
    }
    return 0;
}
