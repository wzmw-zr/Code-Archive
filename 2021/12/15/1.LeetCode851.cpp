/*************************************************************************
	> File Name: 1.LeetCode851.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月15日 星期三 08时34分32秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int dfs(unordered_map<int, vector<int>> &mp, vector<int> &quiet, int ind, vector<int> &check) {
    if (check[ind]) return ind;
    int ans = ind;
    check[ind] = 1;
    for (int x : mp[ind]) {
        auto t = dfs(mp, quiet, x, check);
        if (quiet[t] < quiet[ans]) ans = t;
    }
    return ans;
}

vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    int n = quiet.size();
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) mp[i] = vector<int>();
    for (auto x : richer) mp[x[1]].push_back(x[0]);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        vector<int> check(n, 0);
        ans[i] = dfs(mp, quiet, i, check);
    }
    return ans;
}

int main() {
    return 0;
}
