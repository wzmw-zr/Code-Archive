/*************************************************************************
	> File Name: 3.LeetCode209.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月05日 星期五 00时28分45秒
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

int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size(), l = 0, r = 0, ans = INT32_MAX, sum = 0;
    while (r < n) {
        sum += nums[r++];
        if (sum < s) continue;
        while (sum >= s) sum -= nums[l++];
        ans = min(ans, r - l + 1);
    }
    return ans == INT32_MAX ? 0 : ans;
}


int main() {
    return 0;
}
