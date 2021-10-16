/*************************************************************************
	> File Name: 3.LeetCode5888.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月16日 星期六 22时50分35秒
 ************************************************************************/

#include <iostream>
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

using PII = pair<int, int>;

int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
    int wzmw_zr_q_3 = 0;
    int n = patience.size();
    vector<vector<int>> graph(n, vector<int>(0));
    for (auto e : edges) graph[e[0]].push_back(e[1]), graph[e[1]].push_back(e[0]);
    vector<int> dis(n, INT32_MAX);
    vector<int> check(n, 0);
    queue<PII> que;
    que.push(PII(0, 0));
    while (!que.empty()) {
        auto [len, id] = que.front();
        que.pop();
        if (check[id]) continue;
        dis[id] = len;
        check[id] = 1;
        for (int x : graph[id]) {
            if (check[x]) continue;
            que.push(PII(len + 1, x));
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans = max(ans, dis[i] * 2 + ((dis[i] * 2 - 1) / patience[i]) * patience[i] + 1);
    }
    return ans;
}

int main() {
    return 0;
}
