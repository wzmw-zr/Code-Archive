/*************************************************************************
	> File Name: 2.LeetCode6224.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月23日 星期日 10时42分49秒
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

int gcd(int x, int y) {
  return y == 0 ? x : gcd(y, x % y);
}

int subarrayGCD(vector<int>& nums, int k) {
  int n = nums.size();
  vector<vector<int>> dp(n, vector<int>(n, 1));
  for (int i = 0; i < n; i++)
    dp[i][i] = nums[i];
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      dp[i][j] = gcd(dp[i][j - 1], nums[j]);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++)
      ans += dp[i][j] == k ? 1 : 0;
  }
  return ans;
}

int main() {
  return 0;
}
