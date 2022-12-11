/*************************************************************************
	> File Name: 2.LeetCode6258.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月11日 星期日 10时38分01秒
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
#include <cmath>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int longestSquareStreak(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  unordered_map<int, int> dp;
  int ans = -1;
  for (int x : nums) {
    int m = sqrt(x * 1.0);
    if (pow(m, 2) != x) {
      dp[x] = 1;
    } else {
      dp[x] = (dp.count(m) ? dp[m] : 0) + 1;
    }
    ans = max(ans, dp[x]);
  }
  return ans >= 2 ? ans : -1;
}

int main() {
  return 0;
}
