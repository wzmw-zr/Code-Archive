/*************************************************************************
	> File Name: 1.LeetCode743.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月06日 星期五 10时53分30秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    int dis[n + 1][n + 1];
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 0; i <= n; i++) dis[i][i] = 0;
    for (auto t : times) dis[t[0]][t[1]] = t[2];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dis[k][i]);
    return ans == 0x3f3f3f3f ? -1 : ans;
}

int main() {
    return 0;
}
