/*************************************************************************
	> File Name: 4.LeetCode719.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月08日 星期二 19时50分02秒
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

int calculate(vector<int> &nums, int mid) {
    int left = 0, right = 0, n = nums.size(), cnt = 0;
    for (right = 0; right < n; right++) {
        while (nums[right] - nums[left] > mid) left++;
        cnt += right - left + 1;
    } 
    return cnt;
}

int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums[nums.size() - 1] - nums[0];
    while (left < right) {
        int mid = (left + right) / 2;
        if (calculate(nums, mid) < k) left = mid + 1;
        else right = mid;
    }
    return left;
}


int main() {
    return 0;
}
