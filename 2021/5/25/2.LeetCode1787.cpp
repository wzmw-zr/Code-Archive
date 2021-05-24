/*************************************************************************
	> File Name: 2.LeetCode1787.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月25日 星期二 01时37分43秒
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

int minChanges(vector<int>& nums, int k) {
    int mmax = 1 << 10;
    vector<unordered_map<int, int>> groups(k, unordered_map<int, int>());
    vector<int> cnts(k, 0);
    int dp[k + 1][mmax + 1];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        groups[i % k][nums[i]]++;
        cnts[i % k]++;
    }

    int pre = 0;

    for (int i = 0; i < k; i++) {
        int t = INT32_MAX;
        for (int mask = 0; mask < mmax; mask++) {
            int mmin = pre;
            for (auto &&[x, cnt] : groups[i]) {
                mmin = min(mmin, dp[i][mask ^ x] - cnt);
            }
            dp[i + 1][mask] = mmin + cnts[i];
            t = min(t, mmin + cnts[i]);
        }
        pre = t;
    }
    return dp[k][0];
}

int main() {
    return 0;
}
