/*************************************************************************
	> File Name: 1.LeetCode416.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月11日 星期日 07时19分08秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

bool dfs(vector<int> &nums, int ind, int sum) {
    if (ind == nums.size()) return false;
    if (sum - nums[ind] == 0) return true;
    return dfs(nums, ind + 1, sum - nums[ind]) || dfs(nums, ind + 1, sum);
}

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int &x : nums) sum += x;
    if (sum & 1) return false;
    return dfs(nums, 0, sum / 2);
}

int main() {
    return 0;
}
