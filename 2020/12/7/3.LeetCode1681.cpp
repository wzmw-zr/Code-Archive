/*************************************************************************
	> File Name: 3.LeetCode1681.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月07日 星期一 18时13分03秒
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

int minimumIncompatibility(vector<int>& nums, int k) {
    int n = nums.size(), avg = n / k;
    if (k == n) return 0;
    if (k == 1) {
        set<int> st;
        for (int x : nums) st.insert(x);
        if (st.size() == n) return *(--st.end()) - *st.begin();
        return -1;
    }
    sort(nums.begin(), nums.end());
    int m = 1 << n;
    int dp[m][n];
    memset(dp, 0x3f, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));
    for (int mask = 1; mask < m; mask++) {
        int cnt = __builtin_popcount(mask);
        int rest = cnt % avg;
        if (rest == 0) {
            for (int p = 0; p < n; p++) {
                if (mask & (1 << p)) 
                    dp[mask][0] = min(dp[mask][0], dp[mask & ~(1 << p)][p]);
            }
            for (int pre = 1; pre < n; pre++) dp[mask][pre] = dp[mask][0];
        } else {
            for (int pre = 0, sum1 = 0; pre < n && cnt - sum1 >= rest; pre++) {
                if (!(mask & (1 << pre))) {
                    for (int p = pre + 1; p < n; p++) {
                        if ((mask & (1 << p)) && nums[p] > nums[pre]) 
                            dp[mask][pre] = min(dp[mask][pre], dp[mask & ~(1 << p)][p] + nums[p] - nums[pre]);
                    }
                } else {
                    sum1++;
                }
            }
        }
    }
    if (dp[m - 1][0] >= 10000) return -1;
    return dp[m - 1][0];
}

int main() {
    int k, n;
    cin >> k;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);
    cout << minimumIncompatibility(nums, k) << endl;
    return 0;
}
