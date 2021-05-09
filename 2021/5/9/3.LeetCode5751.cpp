/*************************************************************************
	> File Name: 3.LeetCode5751.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月09日 星期日 10时43分21秒
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

int binary_search(vector<int> &nums, int l, int r, int num) {
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (nums[mid] >= num) l = mid;
        else r = mid - 1;
    }
    return nums[r] >= num ? r : -1;
}

int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int len_1 = nums1.size(), len_2 = nums2.size();
    int ans = 0;
    for (int i = 0; i < len_1; i++) {
        int ind = binary_search(nums2, i, len_2 - 1, nums1[i]);
        if (ind == -1) continue;
        ans = max(ans, ind - i);
    }
    return ans;
}

int main() {
    return 0;
}
