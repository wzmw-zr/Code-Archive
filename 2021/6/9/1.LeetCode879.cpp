/*************************************************************************
	> File Name: 1.LeetCode879.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月09日 星期三 00时13分29秒
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

// WA
const int MOD = 1e9 + 7;

unordered_map<string, int> mp;

int dfs(vector<int> &group, vector<int> &profit, int ind, int &len, int n, int minProfit) {
    if (ind == len) {
        if (minProfit <= 0) return 1;
        return 0;
    }
    string s = to_string(ind) + " " + to_string(n) + " " + to_string(minProfit);
    if (mp.count(s)) return mp[s];
    int cnt = 0;
    cnt += dfs(group, profit, ind + 1, len, n, minProfit);
    cnt %= MOD;
    if (n >= group[ind]) {
        if (profit[ind] >= minProfit) cnt = (cnt + 1) % MOD;
        cnt += dfs(group, profit, ind + 1, len, n - group[ind], minProfit - profit[ind]);
    }
    cnt %= MOD;
    return mp[s] = cnt;
}

int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    int len = group.size();
    return dfs(group, profit, 0, len, n, minProfit);
}

int main() {
    return 0;
}
