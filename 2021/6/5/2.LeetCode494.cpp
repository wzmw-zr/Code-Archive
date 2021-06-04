/*************************************************************************
	> File Name: 2.LeetCode494.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月05日 星期六 00时09分48秒
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

void dfs(int sum, int ind, int n, vector<int> &nums, int &target, int &ans) {
    if (ind == n) {
        if (sum == target) ans++;
        return ;
    }
    dfs(sum + nums[ind], ind + 1, n, nums, target, ans);
    dfs(sum - nums[ind], ind + 1, n, nums, target, ans);
}

int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int ans = 0;
    dfs(0, 0, n, nums, target, ans);
    return ans;
}

int main() {
    return 0;
}
