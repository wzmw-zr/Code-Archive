/*************************************************************************
	> File Name: 2.LeetCode1262.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月02日 星期三 15时27分24秒
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

void dfs(vector<int> &nums, int ind, int sum, int n, int &ans) {
    if (ind == n) {
        if (sum % 3) return ;
        ans = max(ans, sum);
        return ;
    }
    dfs(nums, ind + 1, sum + nums[ind], n, ans);
    dfs(nums, ind + 1, sum, n, ans);
}

int maxSumDivThree(vector<int>& nums) {
    int ans = 0, n = nums.size();
    dfs(nums, 0, 0, n, ans);
    return ans;
}

int main() {
    return 0;
}
