/*************************************************************************
	> File Name: 1.LeetCode643.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月04日 星期四 00时00分52秒
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

double findMaxAverage(vector<int>& nums, int k) {
    double sum = 0.0, ans = INT32_MIN;
    int n = nums.size();
    int l = 0, r = 0;
    while (r < k - 1) sum += nums[r++];
    while (r < n) {
        sum += nums[r++];
        ans = max(ans, sum / k);
        sum -= nums[l++];
    }
    return ans;
}

int main() {
    return 0;
}
