/*************************************************************************
	> File Name: 1.LeetCode1984.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月11日 星期五 00时04分39秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int minimumDifference(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = INT32_MAX;
    for (int i = 0; i <= n - k; i++) {
        ans = min(ans, nums[i + k - 1] - nums[i]);
    }
    return ans;
}

int main() {
    return 0;
}
