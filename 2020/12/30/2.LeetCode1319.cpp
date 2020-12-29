/*************************************************************************
	> File Name: 2.LeetCode1319.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月30日 星期三 00时21分20秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int dfs(vector<vector<int>> &nodes, vector<bool> &check, int ind) {
    if (check[ind]) return 0;
    check[ind] = true;
    for (int x : nodes[ind]) dfs(nodes, check, x);
    return 1;
}

int makeConnected(int n, vector<vector<int>>& connections) {
    if (n > connections.size() + 1) return -1;
    vector<bool> check(n, false);
    vector<vector<int>> nodes(n, vector<int>(0));
    for (auto &x : connections) {
        nodes[x[0]].push_back(x[1]);
        nodes[x[1]].push_back(x[0]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += dfs(nodes, check, i);
    return ans - 1;
}

int main() {
    return 0;
}
