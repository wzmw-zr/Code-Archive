/*************************************************************************
	> File Name: 1.LeetCode2093.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月06日 星期一 10时23分55秒
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

void dfs(int ind, unordered_map<int, vector<int>> &mp, vector<vector<int>> &ans) {
    while (mp[ind].size()) {
        int next = *(mp[ind].rbegin());
        mp[ind].pop_back();
        dfs(next, mp, ans);
        ans.push_back({ind, next});
    }
}

vector<vector<int>> validArrangement(vector<vector<int>> &pairs) {
    unordered_map<int, vector<int>> out;
    unordered_map<int, int> in_deg;
    for (auto x : pairs) {
        for (auto y : x) if (!out.count(y)) out[y] = vector<int>();
    }
    for (auto x : pairs) {
        out[x[0]].push_back(x[1]);
        in_deg[x[1]]++;
        if (!in_deg.count(x[0])) in_deg[x[0]] = 0;
    }
    vector<vector<int>> ans;
    for (auto &&[ind, deg] : in_deg) {
        if (deg == out[ind].size()) continue;
        if (out[ind].size() > deg) {
            dfs(ind, out, ans);
            reverse(ans.begin(), ans.end());
            return ans;
        }
    }
    int ind = (*in_deg.begin()).first;
    dfs(ind, out, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    return 0;
}
