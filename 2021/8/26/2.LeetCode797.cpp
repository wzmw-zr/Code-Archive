/*************************************************************************
	> File Name: 2.LeetCode797.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月26日 星期四 15时47分43秒
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

vector<vector<int>> dfs(vector<vector<int>> &graph, int ind, int n, unordered_map<int, vector<vector<int>>> &mp) {
    if (mp.count(ind)) return mp[ind];
    vector<vector<int>> ans;
    if (ind == n - 1) {
        ans.push_back(vector<int>({ind}));
        mp[ind] = ans;
        return ans;
    }
    for (auto x : graph[ind]) {
        auto temp = dfs(graph, x, n, mp);
        if (temp.size() == 0) continue;
        for (auto t : temp) {
            auto y = t;
            y.push_back(ind);
            ans.push_back(y);
        }
    }
    mp[ind] = ans;
    return ans;
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int n = graph.size();
    unordered_map<int, vector<vector<int>>> mp;
    auto ans = dfs(graph, 0, n, mp);
    for (auto &&x : ans) reverse(x.begin(), x.end());
    return ans;
}

int main() {
    return 0;
}
