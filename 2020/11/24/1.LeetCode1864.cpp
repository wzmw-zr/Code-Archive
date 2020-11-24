/*************************************************************************
	> File Name: 1.LeetCode1864.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月24日 星期二 08时23分17秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
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

int massage(vector<int>& nums) {
    int n = nums.size();
    if (!n) return 0;
    if (n == 1) return nums[0];
    int dp[n + 5][2];
    memset(dp, 0, sizeof(dp));
    dp[0][1] = nums[0], dp[1][1] = nums[1];
    dp[1][0] = max(dp[0][0], dp[0][1]);
    cout << dp[0][0] << " " << dp[0][1] << endl;
    cout << dp[1][0] << " " << dp[1][1] << endl;
    for (int i = 2; i < n; i++) { 
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 2][1]) + nums[i];
        cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
}

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);
    cout << massage(nums) << endl;
    return 0;
}
