/*************************************************************************
	> File Name: 3.ST_table.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月25日 星期五 14时56分20秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

#define LOG_N 30
#define MAX_N 100010

int st[MAX_N + 5][LOG_N + 5], logn[MAX_N + 5];
int n, m, x, y, s;

void init_log() {
    logn[1] = 0;
    logn[2] = 1;
    for (int i = 3; i <= MAX_N; i++) logn[i] = logn[i / 2] + 1;
}

int main() {
    init_log();
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> st[i][0];
    for (int i = 1; i <= LOG_N; i++) {
        for (int j = 0; j + (1 << i) - 1 < n; j++) {
            st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        s = logn[y - x + 1];
        cout << max(st[x][s], st[y - (1 << s) + 1][s]) << endl;
    }
    return 0;
}
