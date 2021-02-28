/*************************************************************************
	> File Name: 3.LeetCode5690.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月28日 星期日 10时35分45秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

void dfs(vector<int> &toppingCosts, int ind, int &m, int cost, unordered_set<int> &costs) {
    costs.insert(cost);
    if (ind == m) return ;
    dfs(toppingCosts, ind + 1, m, cost, costs);
    dfs(toppingCosts, ind + 1, m, cost + toppingCosts[ind], costs);
    dfs(toppingCosts, ind + 1, m, cost + toppingCosts[ind] * 2, costs);
}

int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
    int n = baseCosts.size(), m = toppingCosts.size();
    unordered_set<int> costs;
    for (int i = 0; i < n; i++) {
        int cost = baseCosts[i];
        dfs(toppingCosts, 0, m, cost, costs);
    }
    int dis = INT32_MAX;
    for (int x : costs) dis = min(dis, abs(target - x));
    int ans = INT32_MAX;
    for (int x : costs) {
        if (abs(target - x) != dis) continue;
        ans = min(ans, x);
    }
    return ans;
}

int main() {
    return 0;
}
