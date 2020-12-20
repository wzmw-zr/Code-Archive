/*************************************************************************
	> File Name: 3.LeetCode5631.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月20日 星期日 11时15分23秒
 ************************************************************************/

#include<iostream>
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

int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n + 1, INT32_MIN);
    dp[0] = nums[0];
    multiset<int> st;
    st.insert(dp[0]);
    for (int i = 1; i < n; i++) {
        for (int x : st) cout << x << " ";
        int temp = *(st.rbegin());
        dp[i] = temp + nums[i];
        st.insert(dp[i]);
        if (i >= k) st.erase(st.find(dp[i - k]));
    }
    #if 0
    for (int i = 1; i <= k && i <= n; i++) dp[i] = max(dp[i], dp[0] + nums[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k && i + j < n; j++) dp[i + j] = max(dp[i + j], dp[i] + nums[i + j]);
    }
    #endif
    return dp[n - 1];
}

int main() {
    int k, n;
    vector<int> nums;
    cin >> k;
    while (cin >> n) nums.push_back(n);
    cout << maxResult(nums, k) << endl;
    return 0;
}
