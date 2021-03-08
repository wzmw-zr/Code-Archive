/*************************************************************************
	> File Name: 1.LeetCode132.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月08日 星期一 08时04分48秒
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

int minCut(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> nums(n, INT32_MAX);
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) dp[i][i + 1] = 1;
    }
    for (int l = 3; l <= n; l++) {
        for (int i = 0; i + l <= n; i++) {
            if (s[i] == s[i + l - 1]) dp[i][i + l - 1] = dp[i + 1][i + l - 2];
        }
    }
    for (int i = 0; i <= n; i++) {
        if (dp[0][i]) {
            nums[i] = 0;
            continue;
        }
        for (int j = 1; j <= i; j++) {
            if (!dp[j][i]) continue;
            nums[i] = min(nums[j - 1] + 1, nums[i]);
        }
    }
    return nums[n - 1];
}

int main() {
    return 0;
}
