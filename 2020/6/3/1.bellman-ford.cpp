/*************************************************************************
	> File Name: 1.bellman-ford.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月03日 星期三 18时12分03秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
#define MAX_N 100000

int n, m, s, dis[MAX_N + 5][3], ans[MAX_N + 5];
 
int main() {
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dis[i][0] = a;
        dis[i][1] = b;
        dis[i][2] = c;
    }
    ans[s] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            ans[dis[j][1]] = min(ans[dis[j][1]], ans[dis[j][0]] + dis[j][2]);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
