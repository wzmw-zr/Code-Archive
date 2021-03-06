/*************************************************************************
	> File Name: 4.LeetCode40.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月02日 星期五 08时48分09秒
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


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    int n = candidates.size();
    set<vector<int>> dp[n + 1][target + 1];
    dp[0][0].insert(vector<int>(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= target; j++) {
            for (auto x : dp[i][j]) dp[i + 1][j].insert(x);
            if (j >= candidates[i]) {
                for (auto x : dp[i][j - candidates[i]]) {
                    auto temp = x;
                    temp.push_back(candidates[i]);
                    dp[i + 1][j].insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans;
    for (auto x : dp[n][target]) ans.push_back(x);
    return ans;
}

int main() {
    return 0;
}
