/*************************************************************************
	> File Name: 2.LeetCode312.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月19日 星期日 07时23分44秒
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
    if (len == 0) return 0;
    vector<int> t_nums(len + 2, 1);
    for (int i = 0; i < len; i++) t_nums[i + 1] = nums[i];
    vector<vector<int>> dp(len + 5, vector<int>(len + 5, 1));

    for (int i = 1; i <= len; i++) {
        dp[i][i] = t_nums[i - 1] * t_nums[i] * t_nums[i + 1];
    }

    for (int i = 1; i <= len - 1; i++) {
        int tmp_1 = dp[i][i] + t_nums[i + 1] * t_nums[i - 1] * t_nums[i + 2];
        int tmp_2 = dp[i + 1][i + 1] + t_nums[i - 1] * t_nums[i] * t_nums[i + 2];
        dp[i][i + 1] = max(tmp_1, tmp_2);
    }

    for (int i = 3; i <= len; i++) {
        for (int j = 1; j + i - 1 <= len; j++) {
            for (int k = j; k <= j + i - 1; k++) {
                if (k == j) dp[j][j + i - 1] = max(dp[j][j + i - 1], t_nums[j - 1] * t_nums[k] * t_nums[j + i] + dp[j + 1][j + i - 1]);
                else if (k == j + i - 1) dp[j][j + i - 1] = max(dp[j][j + i - 1], t_nums[j - 1] * t_nums[k] * t_nums[j + i] + dp[j][j + i - 2]);
                else dp[j][j + i - 1] = max(dp[j][j + i - 1], t_nums[j - 1] * t_nums[k] * t_nums[j + i] + dp[k + 1][j + i - 1] + dp[j][k - 1]);
            }
        }
    }
    return dp[1][len];
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << endl;
    cout << maxCoins(nums) << endl;
    return 0;
}
