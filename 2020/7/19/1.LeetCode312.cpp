/*************************************************************************
	> File Name: 1.LeetCode312.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月19日 星期日 00时36分21秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int maxCoins(vector<int>& nums) {
    int len = nums.size();
    vector<vector<int>> dp(len + 5, vector<int>(len + 5, 1));
    for (int i = 1; i <= len; i++) dp[i][i] = nums[i - 1];
    for (int i = 1; i <= len - 1; i++) dp[i][i + 1] = nums[i - 1] * nums[i];
    for (int i = 3; i <= len; i++) {
        for (int j = 1; i + j - 1 <= len; j++) {
            dp[j][i + j - 1] = max(
                dp[j + 1][i + j - 2] + nums[j - 1] * nums[i + j - 2], 
                max(dp[j][i + j - 2] + nums[i + j - 2],
                    dp[j + 1][i + j - 1] + nums[j - 1])
                );
        }
    }
    return dp[1][len];
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << maxCoins(nums) << endl;
    return 0;
}
