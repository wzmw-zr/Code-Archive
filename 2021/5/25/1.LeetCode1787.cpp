/*************************************************************************
	> File Name: 1.LeetCode1787.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月25日 星期二 00时09分16秒
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

// TLE
int dfs(vector<int> &nums, int ind, int &n, int &k, int num, int cnt) {
    if (ind + k > n) return cnt;
    int t = nums[ind + k - 1];
    num ^= t;
    if (num != 0) cnt++;
    int ans = INT32_MAX;
    for (int i = 0; i < k; i++) {
        int temp = nums[ind + i];
        nums[ind + i] ^= num;
        ans = min(ans, dfs(nums, ind + 1, n, k, nums[ind], cnt));
        nums[ind + i] = temp;
    }
    return cnt;
}

int minChanges(vector<int>& nums, int k) {
    int n = nums.size();
    int num = 0;
    for (int i = 0; i < k - 1; i++) 
        num ^= nums[i];
    int ans = dfs(nums, 0, n, k, num, 0);
    return ans;
}

int main() {
    return 0;
}
