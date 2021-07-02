/*************************************************************************
	> File Name: 3.LeetCode39.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月02日 星期五 07时59分55秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
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

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int n = candidates.size();
    vector<vector<int>> dp[n + 1][target + 1];
    dp[0][0] = vector<vector<int>>(1, vector<int>(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= target; j++) {
            for (auto x : dp[i][j]) dp[i + 1][j].push_back(x);
            if (j >= candidates[i]) {
                for (auto x : dp[i + 1][j - candidates[i]]) {
                    auto temp = x;
                    temp.push_back(candidates[i]);
                    dp[i + 1][j].push_back(temp);
                }
            }
        }
    }
    return dp[n][target];
}

int main() {
    return 0;
}
