/*************************************************************************
	> File Name: 2.LeetCode1655.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月07日 星期四 19时52分32秒
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

bool canDistribute(vector<int>& nums, vector<int>& quantity) {
    int m = quantity.size();
    int sum[(1 << m) + 1];
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i < (1 << m); i++) {
        int ind = __builtin_ctz(i);
        sum[i] = quantity[ind] + sum[i - (1 << ind)];
    }
    unordered_map<int, int> mp;
    for (int x : nums) mp[x]++;
    vector<int> cnts;
    for (auto [x, cnt] : mp) cnts.push_back(cnt);
    int n = cnts.size();
    int dp[n + 1][(1 << m) + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int x = (1 << m) - 1, y = (1 << m) - 1; x; x = y & (x - 1)) {
            dp[i + 1][x] = dp[i][x];
            if (cnts[i] < sum[x]) continue;
            dp[i + 1][x] = 1;
            for (int p = (1 << m) - 1 - x, q = (1 << m) - 1 - x; p; p = q & (p - 1)) {
                if (dp[i][p]) dp[i + 1][p | x] = 1;
            }
        }
    }
    return dp[n][(1 << m) - 1];
}

int main() {
    return 0;
}
