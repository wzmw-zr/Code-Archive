/*************************************************************************
	> File Name: 2.LeetCode834.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月06日 星期二 09时17分44秒
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

void dfs(int ind, vector<vector<int>> &graph, vector<int> &dp, vector<int> &sz, vector<int> &check) {
    if (graph[ind].size() == 0)  return ;
    check[ind] = 1;
    for (auto &x : graph[ind]) {
        if (check[x]) continue;
        dfs(x, graph, dp, sz, check);
        sz[ind] += sz[x];
        dp[ind] += dp[x] + sz[x];
    }
    check[ind] = 0;
}

void dfs(int pre, int ind, vector<vector<int>> &graph, vector<int> &dp, vector<int> &sz, vector<int> &ans, vector<int> &check) {
    if (check[ind]) return ;
    check[ind] = 1;
    int d_1 = dp[pre], d_2 = dp[ind], s_1 = sz[pre], s_2 = sz[ind];
    dp[pre] -= dp[ind] + sz[ind];
    sz[pre] -= sz[ind];
    dp[ind] += dp[pre] + sz[pre];
    sz[ind] += sz[pre];
    ans[ind] = dp[ind];
    for (auto &x : graph[ind]) {
        if (check[x]) continue;
        dfs(ind, x, graph, dp, sz, ans, check);
    }
    dp[pre] = d_1, dp[ind] = d_2, sz[pre] = s_1, sz[ind] = s_2;
}

vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    vector<int> dp(N, 0), sz(N, 1), ans(N, 0), check(N, 0);
    vector<vector<int>> graph(N);
    for (int i = 0; i < N - 1; i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    dfs(0, graph, dp, sz, check);
    ans[0] = dp[0];
    check[0] = 1;
    for (auto &x : graph[0]) {
        dfs(0, x, graph, dp, sz, ans, check);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges;
    vector<int> edge(2);
    for (int i = 1; i < n; i++) {
        cin >> edge[0] >> edge[1];
        edges.push_back(edge);
    }
    vector<int> ans = sumOfDistancesInTree(n, edges);
    for (auto &x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
