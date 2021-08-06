/*************************************************************************
	> File Name: 4.LeetCode847.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月06日 星期五 20时10分22秒
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

using PVI = pair<vector<int>, int>;

bool is_end(vector<int> &check) {
    for (int x : check) {
        if (!x) return false;
    }
    return true;
}

void dfs(vector<vector<int>> &graph, vector<int> &check, int &ans, map<PVI, int> &mp, int ind, int dis) {
    if (is_end(check)) {
        ans = min(ans, dis);
        return ;
    }
    for (int x : graph[ind]) {
        int t = check[x];
        check[x] = 1;
        PVI temp(check, x);
        if (!(mp.count(temp)) || mp[temp] > (dis + 1)) {
            mp[temp] = dis + 1;
            dfs(graph, check, ans, mp, x, dis + 1);
        }
        check[x] = t;
    }
}

int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> check(n, 0);
    map<PVI, int> mp;
    int ans = INT32_MAX;
    for (int i = 0; i < n; i++) {
        check[i] = 1;
        mp[PVI(check, i)] = 1;
        dfs(graph, check, ans, mp, i, 0);
        mp[PVI(check, i)] = 0;
        check[i] = 0;
    }
    return ans;
}

int main() {
    return 0;
}
