/*************************************************************************
	> File Name: 3.LeetCode5759.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月16日 星期日 10时31分02秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void dfs(vector<int> &nums, int ind, int &n, int sum, int &ans) {
    if (ind == n) {
        ans += sum;
        return ;
    }
    dfs(nums, ind + 1, n, sum, ans);
    dfs(nums, ind + 1, n, sum ^ nums[ind], ans);
}

int subsetXORSum(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    dfs(nums, 0, n, 0, ans);
    return ans;
}

int main() {
    return 0;
}
