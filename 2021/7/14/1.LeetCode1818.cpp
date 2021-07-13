/*************************************************************************
	> File Name: 1.LeetCode1818.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月14日 星期三 00时03分41秒
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

const long MOD = 1e9 + 7;

int find_left(vector<int> &nums, int target) {
    int l = 0, r = (int) nums.size() - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (nums[mid] <= target) l = mid;
        else r = mid - 1;
    }
    return l;
}

int find_right(vector<int> &nums, int target) {
    int l = 0, r = (int) nums.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] >= target) r = mid;
        else l = mid + 1;
    }
    return l;
}

int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<int> temp = nums1;
    sort(temp.begin(), temp.end());
    long sum = 0;
    for (int i = 0; i < n; i++) sum = sum + (long) abs(nums1[i] - nums2[i]);
    long ans = sum;
    for (int i = 0; i < n; i++) {
        int ind_1 = find_left(temp, nums2[i]);
        int ind_2 = find_right(temp, nums2[i]);
        long t = min(abs(temp[ind_1] - nums2[i]), abs(temp[ind_2] - nums2[i]));
        ans = min(ans, sum - (long) abs(nums1[i] - nums2[i]) + t);
    }
    return ans % MOD;
}

int main() {
    return 0;
}
