/*************************************************************************
	> File Name: 1.LeetCode1995.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月29日 星期三 10时01分24秒
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

int countQuadruplets(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for (int c = n - 2; c >= 0; c--) {
        unordered_map<int, int> mp;
        for (int d = c + 1; d < n; d++) mp[nums[d] - nums[c]]++;
        for (int a = 0; a < c; a++) {
            for (int b = a + 1; b < c; b++) {
                if (mp.count(nums[a] + nums[b])) ans += mp[nums[a] + nums[b]];
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}
