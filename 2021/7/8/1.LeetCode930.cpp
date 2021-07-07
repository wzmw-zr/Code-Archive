/*************************************************************************
	> File Name: 1.LeetCode930.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月08日 星期四 00时03分52秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int, int> mp;
    int ans = 0;
    int n = nums.size();
    mp[nums[0]]++;
    if (nums[0] == goal) ans++;
    for (int i = 1; i < n; i++) {
        nums[i] += nums[i - 1];
        if (mp.count(nums[i] - goal)) ans += mp[nums[i] - goal];
        if (nums[i] == goal) ans++;
        mp[nums[i]]++;
    }
    return ans;
}

int main() {
    return 0;
}
