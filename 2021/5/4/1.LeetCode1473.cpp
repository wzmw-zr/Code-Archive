/*************************************************************************
	> File Name: 1.LeetCode1473.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月04日 星期二 00时05分08秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
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

void dfs(vector<int> &houses, vector<vector<int>> &cost, int &m, int &n, int &target, int ind, int cnt, int price, int &ans) {
    if (ind == m) {
        if (cnt == target)
            ans = min(ans, price);
        return ;
    }
    if (cnt > target) return ;
    if (houses[ind]) {
        if (ind == 0) 
            dfs(houses, cost, m, n, target, ind + 1, cnt + 1, price, ans);
        else {
            if (houses[ind] == houses[ind - 1]) 
                dfs(houses, cost, m, n, target, ind + 1, cnt, price, ans);
            else 
                dfs(houses, cost, m, n, target, ind + 1, cnt + 1, price, ans);
        }
    } else {
        for (int i = 0; i < n; i++) {
            houses[ind] = i + 1;
            if (ind == 0) 
                dfs(houses, cost, m, n, target, ind + 1, cnt + 1, price + cost[ind][i], ans);
            else {
                if (houses[ind] == houses[ind - 1]) 
                    dfs(houses, cost, m, n, target, ind + 1, cnt, price + cost[ind][i], ans);
                else 
                    dfs(houses, cost, m, n, target, ind + 1, cnt + 1, price + cost[ind][i], ans);
            }
        }
        houses[ind] = 0;
    }
}

int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    int ans = INT32_MAX;
    dfs(houses, cost, m, n, target, 0, 0, 0, ans);
    return ans == INT32_MAX ? -1 : ans;
}

int main() {
    return 0;
}
