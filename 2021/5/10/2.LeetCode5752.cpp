/*************************************************************************
	> File Name: 2.LeetCode5752.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月10日 星期一 00时18分35秒
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

const int MOD = 1e9 + 7;

int maxSumMinProduct(vector<int>& nums) {
    int n = nums.size();
    vector<long> pre_sum(n + 1, 0);
    vector<int> pre(n, -1);
    vector<int> after(n, n);
    for (int i = 0; i < n; i++) 
        pre_sum[i + 1] = pre_sum[i] + (long) nums[i];

    stack<int> left, right;
    for (int i = 0; i < n; i++) {
        while (!left.empty() && nums[left.top()] >= nums[i]) 
            left.pop();
        if (!left.empty()) 
            pre[i] = left.top();
        left.push(i);
    }
    for (int i = n - 1; i >= 0; i--) {
        while (!right.empty() && nums[right.top()] >= nums[i]) 
            right.pop();
        if (!right.empty()) 
            after[i] = right.top();
        right.push(i);
    }
    long ans = 0;
    for (int i = 0; i < n; i++) {
        long temp = (long) nums[i] * (pre_sum[after[i]] - pre_sum[pre[i] + 1]);
        ans = max(ans, temp);
    }
    ans %= MOD;
    return ans;
}


int main() {
    return 0;
}
