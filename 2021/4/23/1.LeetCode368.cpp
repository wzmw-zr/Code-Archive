/*************************************************************************
	> File Name: 1.LeetCode368.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月23日 星期五 00时07分05秒
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

vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> dp(n, 0);
    vector<int> pre(n);
    int max_len = 0;
    for (int i = 0; i < n; i++) pre[i] = i;
    for (int i = 0; i < n; i++) {
        int mmax = INT32_MIN;
        int pre_ind = i;
        for (int j = 0; j <= i; j++) {
            if (nums[i] % nums[j] == 0) {
                if (dp[j] > mmax) pre_ind = j;
                mmax = max(mmax, dp[j]);
            }
        }
        pre[i] = pre_ind;
        dp[i] = mmax + 1;
        max_len = max(max_len, dp[i]);
    }
    int max_set_ind = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] < max_len) continue;
        max_set_ind = i;
        break;
    }
    vector<int> ans;
    for (int i = 0; i < max_len; i++) {
        ans.push_back(nums[max_set_ind]);
        max_set_ind = pre[max_set_ind];
    }
    return ans;
}

int main() {
    return 0;
}
