/*************************************************************************
	> File Name: 1.LeetCode673.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月20日 星期一 08时56分46秒
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
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;

using PII = pair<int, int>;

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    long dp[n][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) dp[i][0] = dp[i][1] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] <= nums[j]) continue;
            if (dp[i][0] < dp[j][0] + 1) {
                dp[i][0] = dp[j][0] + 1;
                dp[i][1] = dp[j][1];
            } else if (dp[i][0] == dp[j][0] + 1) {
                dp[i][1] += dp[j][1];
            }
        }
    }
    int mmax = 0;
    long ans = 0;
    for (int i = 0; i < n; i++) {
        if (mmax < dp[i][0]) {
            mmax = dp[i][0];
            ans = dp[i][1];
        } else if (mmax == dp[i][0]) ans += dp[i][1];
    }
    return ans;
}

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);
    cout << findNumberOfLIS(nums) << endl;
    return 0;
}
