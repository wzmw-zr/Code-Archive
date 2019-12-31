/*************************************************************************
	> File Name: 10.HOJ43.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月28日 星期六 18时04分02秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 1000
using namespace std;

int num[max_n + 5][max_n + 5];
int max_num[max_n + 5][max_n + 5];

int dfs(int x, int y, int n) {
    if (x + 1 == n) return num[x][y];
    if (max_num[x][y]) return max_num[x][y];
    max_num[x][y] = max(dfs(x + 1, y, n), dfs(x + 1, y + 1, n)) + num[x][y];
    return max_num[x][y];
}

int main() {
    memset(num, 0, sizeof(num));
    memset(max_num, 0, sizeof(max_num));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) cin >> num[i][j];
    }
    cout << dfs(0, 0, n) << endl;
    return 0;
}
