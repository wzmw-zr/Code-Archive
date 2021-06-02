/*************************************************************************
	> File Name: 1.LeetCode525.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月03日 星期四 00时06分01秒
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

int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    vector<int> ones(n + 1, 0);
    vector<int> zeros(n + 1, 0);
    for (int i = 0; i < n; i++) {
        ones[i + 1] = ones[i] + nums[i];
        zeros[i + 1] = zeros[i] + (1 - nums[i]);
    }
    int ans = 0;
    unordered_map<int, int> mp;
    mp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int t = ones[i] - zeros[i];
        if (!mp.count(t)) {
            mp[t] = i;
            continue;
        }
        ans = max(ans, i - mp[t]);
    }
    return ans;
}

int main() {
    return 0;
}
