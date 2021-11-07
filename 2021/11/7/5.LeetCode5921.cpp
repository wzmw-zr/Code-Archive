/*************************************************************************
	> File Name: 5.LeetCode5921.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月07日 星期日 21时00分33秒
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

struct Node {
    int id;
    int val;
    vector<PII> next;

    Node() = default;
    Node(int id, int val) : id(id), val(val), next(vector<PII>(0)) {}
};

void dfs(int ind, vector<Node> &nodes, vector<int> &check, int cost, int &sum, int &maxTime, int &ans) {
    if (cost > maxTime) return ;
    if (ind == 0) ans = max(ans, sum);
    if (!check[ind]) {
        check[ind] = 1;
        sum += nodes[ind].val;
        if (ind == 0) ans = max(ans, sum);
        for (auto &&[id, t] : nodes[ind].next) dfs(id, nodes, check, cost + t, sum, maxTime, ans);
        sum -= nodes[ind].val;
        check[ind] = 0;
    } else {
        for (auto &&[id, t] : nodes[ind].next) dfs(id, nodes, check, cost + t, sum, maxTime, ans);
    }
}

int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
    int n = values.size();
    vector<Node> nodes(n);
    for (int i = 0; i < n; i++) nodes[i].id = i, nodes[i].val = values[i];
    for (auto e: edges) {
        nodes[e[0]].next.push_back(PII(e[1], e[2]));
        nodes[e[1]].next.push_back(PII(e[0], e[2]));
    }
    vector<int> check(n, 0);
    int cost = 0;
    int sum = 0;
    int ans = 0;
    dfs(0, nodes, check, cost, sum, maxTime, ans);
    return ans;
}

int main() {
    return 0;
}
