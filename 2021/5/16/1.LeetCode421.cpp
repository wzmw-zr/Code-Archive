/*************************************************************************
	> File Name: 1.LeetCode421.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月16日 星期日 00时03分27秒
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

int findMaximumXOR(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    int mmin = INT32_MAX;
    for (int i = 0; i < n; i++) 
        if (nums[i] != 0)
            mmin = min(mmin, __builtin_clz(nums[i]));
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) continue;
        if (__builtin_clz(nums[i]) != mmin) continue;
        for (int j = 0; j < n; j++) 
            ans = max(ans, nums[i] ^ nums[j]);
    }
    return ans;
}

int main() {
    return 0;
}
