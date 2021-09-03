/*************************************************************************
	> File Name: 4.LeetCode1984.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月03日 星期五 14时05分16秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int minimumDifference(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = INT32_MAX;
    for (int i = 0; i + k - 1 < n; i++) ans = min(ans, nums[i + k - 1] - nums[i]);
    return ans;
}

int main() {
    return 0;
}
