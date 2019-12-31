/*************************************************************************
	> File Name: 8.EP18.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月28日 星期六 16时16分08秒
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

int num[max_n + 5][max_n + 5];
int max_num[max_n + 5][max_n + 5] = {0};

int dfs(int i, int j, int n) {
    if (i + 1 == n) return num[i][j];
    if (max_num[i][j]) return max_num[i][j];
    return max_num[i][j] = max(dfs(i + 1, j, n), dfs(i + 1, j + 1, n)) + num[i][j];
}


int main() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j <= i; j++) cin >> num[i][j];
    }
    cout << dfs(0, 0, 15) << endl;
    return 0;
}
