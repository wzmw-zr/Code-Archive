/*************************************************************************
	> File Name: 4.LeetCode560.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月11日 星期二 20时44分33秒
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

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> pre_sum(n + 1, 0);
    for (int i = 0; i < n; i++)
        pre_sum[i + 1] = pre_sum[i] + nums[i];
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = n; i >= 0; i--) {
        if (!mp.count(pre_sum[i] + k)) {
            mp[pre_sum[i]]++;
            continue;
        }
        ans += mp[pre_sum[i] + k];
        mp[pre_sum[i]]++;
    }
    return ans;
}

int main() {
    return 0;
}
