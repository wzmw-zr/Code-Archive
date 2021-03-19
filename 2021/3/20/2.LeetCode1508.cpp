/*************************************************************************
	> File Name: 2.LeetCode1508.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月20日 星期六 00时15分50秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int rangeSum(vector<int>& nums, int n, int left, int right) {
    const int mod = 1e9 + 7;
    int ans = 0;
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];
    vector<int> area_sum;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            area_sum.push_back(pre[j + 1] - pre[i]);
        }
    }
    sort(area_sum.begin(), area_sum.end());
    for (int i = left - 1; i < right; i++) ans = (ans + area_sum[i]) % mod;
    return ans;
}

int main() {
    return 0;
}
