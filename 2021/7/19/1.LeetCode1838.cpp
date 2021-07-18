/*************************************************************************
	> File Name: 1.LeetCode1838.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月19日 星期一 00时10分55秒
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

int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    long l = 0, r = 1, n = nums.size();
    long ans = 1;
    long steps = 0;
    while (r < n) {
        steps += (r - l) * static_cast<long>(nums[r] - nums[r - 1]);
        int t = nums[r];
        while ((r < n) && (nums[r] == t)) r++;
        while (steps > k) {
            steps -= t - nums[l];
            l++;
        }
        ans = max(ans, r - l);
    }
    return static_cast<int>(ans);
}

int main() {
    return 0;
}
