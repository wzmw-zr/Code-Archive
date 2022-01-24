/*************************************************************************
	> File Name: 1.LeetCode2045.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月24日 星期一 10时25分58秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

using PII = pair<int, int>;

int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    vector<vector<int>> graph(n + 1, vector<int>(0));
    for (auto &&edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    vector<int> dis1(n + 1, INT32_MAX);
    vector<int> dis2(n + 1, INT32_MAX);
    queue<PII> que;
    que.push(PII(0, 1));
    while (!que.empty()) {
        auto [dis, ind] = que.front();
        que.pop();
        if (dis >= dis2[ind]) continue;
        if (dis <= dis1[ind]) {
            if (dis != dis1[ind]) dis2[ind] = dis1[ind];
            dis1[ind] = dis;
        } else {
            dis2[ind] = dis;
        }
        for (int next_ind : graph[ind]) {
            que.push(PII(dis + 1, next_ind));
        }
    }
    int t = dis2[n];
    int cost = 0;
    while (t) {
        cost += time;
        if ((--t) && (cost / change) & 1) cost = (cost / change + 1) * change;
    }
    return cost;
}

int main() {
    return 0;
}
