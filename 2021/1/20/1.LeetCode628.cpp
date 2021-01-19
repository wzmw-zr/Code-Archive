/*************************************************************************
	> File Name: 1.LeetCode628.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月20日 星期三 00时01分40秒
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

int maximumProduct(vector<int>& nums) {
    if (nums.size() == 3) return nums[0] * nums[1] * nums[2];
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (nums[n - 1] == 0) return 0;
    if (nums[0] > 0 || nums[n - 1] < 0) return nums[n - 1] * nums[n - 2] * nums[n - 3];
    int ans = max(nums[0] * nums[1] * nums[n - 1], nums[n - 1] * nums[n - 2] * nums[n - 3]);
    return ans;
}

int main() {
    return 0;
}
