/*************************************************************************
	> File Name: 1.LeetCode494.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月07日 星期一 00时04分10秒
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

void dfs(int ind, int &n, int sum, vector<int> &nums, int &target, int &ans) {
    if (ind == n) {
        if (target == sum) ans++;
        return ;
    }
    dfs(ind + 1, n, sum + nums[ind], nums, target, ans);
    dfs(ind + 1, n, sum - nums[ind], nums, target, ans);
}

int findTargetSumWays(vector<int>& nums, int target) {
    int ans = 0;
    int n = nums.size();
    dfs(0, n, 0, nums, target, ans);
    return ans;
}

int main() {
    return 0;
}
