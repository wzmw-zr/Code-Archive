/*************************************************************************
	> File Name: 3.LeetCode377.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月24日 星期六 00时32分19秒
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

int combinationSum4(vector<int>& nums, int target) {
    int dp[target + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= target; i++) {
        for (int &x : nums) {
            if (x <= i) {
                if (INT32_MAX - dp[i] >= dp[i - x]) dp[i] += dp[i - x];
            }
        }
    }
    return dp[target];
}

int main() {
    return 0;
}
