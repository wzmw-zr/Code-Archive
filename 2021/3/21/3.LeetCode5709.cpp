/*************************************************************************
	> File Name: 3.LeetCode5709.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月21日 星期日 10时31分00秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int maxAscendingSum(vector<int>& nums) {
    int ans = 0;
    int sum = nums[0];
    int pre = nums[0];
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        if (nums[i] > pre) sum += nums[i], pre = nums[i];
        else {
            ans = max(ans, sum);
            sum = nums[i];
            pre = nums[i];
        }
    }
    ans = max(ans, sum);
    return ans;
}

int main() {
    return 0;
}
