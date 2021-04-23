/*************************************************************************
	> File Name: 1.LeetCode377.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月24日 星期六 00时03分24秒
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

// WA
int combinationSum4(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int dp[n + 1][target + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < n; j++) {
            if (nums[j] > i) dp[j + 1][i] = dp[j][i];
            else dp[j + 1][i] = dp[j][i] + dp[j + 1][i - nums[j]];
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= target; j++) cout << dp[i][j] << " ";
        cout << endl;
    }
    return dp[n][target];
}

int main() {
    int target, num;
    cin >> target;
    vector<int> nums;
    while (cin >> num) nums.push_back(num);
    cout << combinationSum4(nums, target) << endl;
    return 0;
}
