/*************************************************************************
	> File Name: 1.LeetCode523.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月02日 星期三 00时02分53秒
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

bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mp;
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) 
        pre[i + 1] = pre[i] + nums[i];
    mp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int r = pre[i] % k;
        if (!mp.count(r)) {
            mp[r] = i;
        } else {
            if (i - mp[r] == 1) continue;
            return true;
        }
    }
    return false;
}

int main() {
    return 0;
}
