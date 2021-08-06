/*************************************************************************
	> File Name: 5.LeetCode847.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月06日 星期五 20时35分30秒
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

void dfs(vector<vector<int>> &graph, vector<vector<int>> &check, int cover, int ind, int dis, int &ans, int &n) {
    if (cover == ((1 << n) - 1)) {
        ans = min(ans, dis);
        return ;
    }
    for (int x : graph[ind]) {
        int t = cover | (1 << x);
        if (check[t][x] > (dis + 1)) {
            check[t][x] = dis + 1;
            dfs(graph, check, t, x, dis + 1, ans, n);
        }
    }
}

int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    int ans = INT32_MAX;
    vector<vector<int>> check(1 << n, vector<int>(n, INT32_MAX));
    for (int i = 0; i < n; i++) {
        check[1 << i][i] = 0;
        dfs(graph, check, 1 << i, i, 0, ans, n);
    }
    return ans;
}

int main() {
    return 0;
}
