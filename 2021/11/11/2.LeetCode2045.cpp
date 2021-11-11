/*************************************************************************
	> File Name: 2.LeetCode2045.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月11日 星期四 18时14分38秒
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

int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    vector<vector<int>> graph(n + 1, vector<int>(0));
    for (auto &&e : edges) graph[e[0]].push_back(e[1]), graph[e[1]].push_back(e[0]);
    vector<int> dist1(n + 1, INT32_MAX);
    vector<int> dist2(n + 1, INT32_MAX);
    using PII = pair<int, int>;
    queue<PII> que;
    que.push(PII(0, 1));
    while (!que.empty()) {
        auto [dis, ind] = que.front();
        que.pop();
        if (dist2[ind] <= dis) continue;
        if (dist1[ind] > dis) {
            dist2[ind] = dist1[ind];
            dist1[ind] = dis;
        } else if (dist1[ind] < dis) dist2[ind] = dis;
        for (auto x : graph[ind]) que.push(PII(dis + 1, x));
    }
    int cost = 0;
    int t = dist2[n];
    while (t) {
        cost += time;
        if ((--t) && ((cost / change) & 1)) cost = (cost / change + 1) * change;
    }
    return cost;
}

int main() {
    return 0;
}
