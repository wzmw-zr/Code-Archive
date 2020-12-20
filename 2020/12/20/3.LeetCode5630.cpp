/*************************************************************************
	> File Name: 3.LeetCode5630.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月20日 星期日 10时42分12秒
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

int maximumUniqueSubarray(vector<int>& nums) {
    unordered_map<int, int> mp;
    int left = 0, right = 0, ans = 0, n = nums.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = nums[i] + pre[i];
    while (right != n) {
        if (!mp.count(nums[right])) {
            mp[nums[right]] = right;
            right++;
            continue;
        }
        ans = max(ans, pre[right] - pre[left]);
        int ind = mp[nums[right]];
        for (int i = left; i <= ind; i++) mp.erase(mp.find(nums[i]));
        left = ind + 1;
        mp[nums[right]] = right;
        right++;
    }
    ans = max(ans, pre[right] - pre[left]);
    return ans;
}

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);
    cout << maximumUniqueSubarray(nums) << endl;
    return 0;
}
