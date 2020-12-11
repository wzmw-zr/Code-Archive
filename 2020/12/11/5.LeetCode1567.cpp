/*************************************************************************
	> File Name: 5.LeetCode1567.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月11日 星期五 19时17分05秒
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

void spilit(vector<int> &nums, vector<vector<int>> &arrs) {
    int ind = 0, n = nums.size();
    while (ind < n) {
        while (ind < n && nums[ind] == 0) ind++;
        vector<int> temp;
        while (ind < n && nums[ind] != 0) temp.push_back(nums[ind++]);
        if (temp.size()) arrs.push_back(temp);
    }
}

int get_max_len(vector<int> &nums) {
    int n = nums.size();
    vector<int> cnt(n + 1, 0);
    vector<int> odd;
    for (int i = 0; i < n; i++) {
        cnt[i + 1] = cnt[i];
        cnt[i + 1] += (nums[i] > 0 ? 0 : 1);
        if (cnt[i + 1] & 1) odd.push_back(i);
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (cnt[i] & 1) continue;
        ans = i;
    }
    if (odd.size() >= 2) ans = max(ans, odd[odd.size() - 1] - odd[0]);
    return ans;
}

int getMaxLen(vector<int>& nums) {
    vector<vector<int>> arrs;
    spilit(nums, arrs);
    int ans = 0;
    for (auto &x : arrs) ans = max(ans, get_max_len(x));
    return ans;
}

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);
    cout << getMaxLen(nums) << endl;
    return 0;
}
