/*************************************************************************
	> File Name: 3.LeetCode638.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月06日 星期三 19时02分48秒
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

bool check(vector<int> &nums) {
    for (int &x : nums) {
        if (x) return false;
    }
    return true;
}

bool can_use(vector<int> &scheme, vector<int> &needs) {
    for (int i = 0; i < needs.size(); i++) {
        if (needs[i] < scheme[i]) return false;
    }
    return true;
}

void minus_vector(vector<int> &needs, vector<int> &scheme) {
    for (int i = 0; i < needs.size(); i++) needs[i] -= scheme[i];
}

void add_vector(vector<int> &needs, vector<int> &scheme) {
    for (int i = 0; i < needs.size(); i++) needs[i] += scheme[i];
}

void dfs(vector<int> &prices, vector<vector<int>> &special, vector<int> &needs, int cost, int &ans) {
    if (check(needs)) {
        ans = min(ans, cost);
        return ;
    }
    for (int i = 0; i < prices.size(); i++) {
        if (needs[i] == 0) continue;
        needs[i] -= 1;
        dfs(prices, special, needs, cost + prices[i], ans);
        needs[i] += 1;
    }
    for (int i = 0; i < special.size(); i++) {
        if (!can_use(special[i], needs)) continue;
        minus_vector(needs, special[i]);
        dfs(prices, special, needs, cost + *special[i].rbegin(), ans);
        add_vector(needs, special[i]);
    }
}

int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    int mmin = INT32_MAX;
    dfs(price, special, needs, 0, mmin);
    return mmin;
}

int main() {
    return 0;
}
