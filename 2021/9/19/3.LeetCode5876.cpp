/*************************************************************************
	> File Name: 3.LeetCode5876.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月19日 星期日 10时33分45秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int sumOfBeauties(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n + 1, 0);
    vector<int> suf(n + 1, INT32_MAX);
    pre[0] = nums[0];
    for (int i = 1; i < n; i++) pre[i] = max(pre[i - 1], nums[i]);
    suf[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) suf[i] = min(suf[i + 1], nums[i]);
    int ans = 0;
    for (int i = 1; i <= n - 2; i++) {
        if (pre[i - 1] < nums[i] && nums[i] < suf[i + 1]) ans += 2;
        else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) ans += 1;
    }
    return ans;
}

int main() {
    return 0;
}
