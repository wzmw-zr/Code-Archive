/*************************************************************************
	> File Name: 2.LeetCode416.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月11日 星期日 08时01分36秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;


bool canPartition(vector<int>& nums) {
    if (nums.size() < 2) return false;
    int sum = 0;
    for (int &x : nums) sum += x;
    if (sum & 1) return false;
    vector<vector<bool>> dp(nums.size() + 5, vector<bool>(sum / 2 + 5, false));
    for (int i = 0; i < nums.size(); i++) dp[i][0] = true;
    dp[0][nums[0]] = true;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 1; j <= sum / 2; j++) {
            if (j < nums[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
        }
    }
    return dp[nums.size() - 1][sum / 2];
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (canPartition(nums) ? "Yes" : "No") << endl;
    return 0;
}
