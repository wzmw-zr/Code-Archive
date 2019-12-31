/*************************************************************************
	> File Name: 1.EP18.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月28日 星期六 09时09分36秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 20
using namespace std;

int val[max_n + 5][max_n + 5];
int max_val[max_n + 5][max_n + 5];
int dfs(int i, int j, int n) {
    if (i + 1 == n) return val[i][j];
    if (max_val[i][j]) return max_val[i][j];
    max_val[i][j] = max(dfs(i + 1, j, n), dfs(i + 1, j + 1, n)) + val[i][j];
    return max_val[i][j];
}

int main() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> val[i][j];
        }
    }
    memset(max_val, 0, sizeof(max_val));
    cout << dfs(0, 0, max_n) << endl;
    return 0;
}
