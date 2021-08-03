/*************************************************************************
	> File Name: 2.LeetCode611.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月04日 星期三 00时21分13秒
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

int binary_search(vector<int> &nums, int sum, int l, int r) {
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (nums[mid] < sum) l = mid;
        else r = mid - 1;
    }
    return l;
}

int triangleNumber(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((j + 1) == n) continue;
            if ((nums[i] + nums[j]) <= nums[j + 1]) continue;
            int ind = binary_search(nums, nums[i] + nums[j], j + 1, n - 1);
            ans += ind - j;
        }
    }
    return ans;
}

int main() {
    return 0;
}
