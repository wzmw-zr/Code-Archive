/*************************************************************************
	> File Name: 2.LeetCode523.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月02日 星期三 00时22分11秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + nums[i];
    for (int i = 0; i <= n; i++) {
        for (int j = i + 2; j <= n; j++) {
            if ((pre[j] - pre[i]) % k == 0) return true;
        }
    }
    return false;
}

int main() {
    return 0;
}
