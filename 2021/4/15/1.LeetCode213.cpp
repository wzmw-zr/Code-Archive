/*************************************************************************
	> File Name: 1.LeetCode213.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月15日 星期四 00时07分05秒
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

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> house = nums;
    for (int &x : nums) house.push_back(x);
    int dp[2 * n][2 * n][2][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 2 * n; i++) dp[i][i][1][1] = house[i];
    for (int i = 0; i < 2 * n - 1; i++) {
        dp[i][i + 1][1][0] = house[i];
        dp[i][i + 1][0][1] = house[i + 1];
    }
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i + len - 1 < 2 * n; i++) {
            dp[i][i + len - 1][0][0] = 
                max(
                    max(dp[i + 1][i + len - 1][0][0], dp[i + 1][i + len - 1][1][0]), 
                    max(dp[i][i + len - 2][0][0], dp[i][i + len - 2][0][1])
                );
            dp[i][i + len - 1][1][0] = max(dp[i + 1][i + len - 1][0][0] + house[i], dp[i][i + len - 2][1][1]);
            dp[i][i + len - 1][0][1] = max(dp[i][i + len - 2][0][0] + house[i + len - 1], dp[i + 1][i + len - 1][1][1]);
            dp[i][i + len - 1][1][1] = max(dp[i][i + len - 2][1][0] + house[i + len - 1], dp[i + 1][i + len - 1][0][1]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int temp = max(max(dp[i][i + n - 1][0][0], dp[i][i + n - 1][0][1]), dp[i][i + n - 1][1][0]);
        ans = max(ans, temp);
    }
    if (n == 1) ans = nums[0];
    return ans;
}

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);
    cout << rob(nums) << endl;
    return 0;
}
