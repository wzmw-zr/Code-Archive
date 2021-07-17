/*************************************************************************
	> File Name: 1.LeetCode2017.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月17日 星期六 08时40分34秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int ans = nums[0];
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        nums[i] = max(nums[i], nums[i - 1] + nums[i]);
        ans = max(ans, nums[i]);
    }
    return ans;
}

int main() {
    return 0;
}
