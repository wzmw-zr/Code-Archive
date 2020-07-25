/*************************************************************************
	> File Name: 1.LeetCode410.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月25日 星期六 08时05分44秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int splitArray(vector<int>& nums, int m) {
    long len = nums.size();
    vector<long> sum(len + 5, 0);
    vector<vector<long>> dp(m + 5, vector<long>(len + 5, 0x3f3f3f3f3f3f3f3f));
    for (long i = 1; i <= len; i++) {
        sum[i] = sum[i - 1] + nums[i - 1];
        dp[1][i] = sum[i];
    }
    for (long i = 2; i <= m; i++) {
        for (long j = i; j <= len; j++) {
            for (long k = i - 1; k < j; k++) {
                dp[i][j] = min(max(dp[i - 1][k], sum[j] - sum[k]), dp[i][j]);
            }
        }
    }
    return dp[m][len];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << splitArray(nums, m) << endl;
    return 0;
}
