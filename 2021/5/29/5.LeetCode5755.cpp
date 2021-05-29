/*************************************************************************
	> File Name: 5.LeetCode5755.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月29日 星期六 22时34分19秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int l = 0, r = (int) nums.size() - 1;
    int ans = INT32_MIN;
    while (l < r) {
        ans = max(ans, nums[l] + nums[r]);
        l++, r--;
    }
    return ans;
}

int main() {
    return 0;
}
