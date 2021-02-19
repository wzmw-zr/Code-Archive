/*************************************************************************
	> File Name: 1.LeetCode697.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月20日 星期六 00时02分18秒
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

int get_len(vector<int> &nums, int &x) {
    int l = 0, r = nums.size() - 1;
    while (l < r && nums[l] != x) l++;
    while (l < r && nums[r] != x) r--;
    return r - l + 1;
}

int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (int &x : nums) mp[x]++;
    int degree = 0;
    for (auto &&[x, cnt] : mp) degree = max(degree, cnt);
    vector<int> candidates;
    for (auto &&[x, cnt] : mp) {
        if (cnt == degree) candidates.push_back(x);
    }
    int ans = INT32_MAX;
    for (int &x : candidates) ans = min(ans, get_len(nums, x));
    return ans;
}

int main() {
    return 0;
}
