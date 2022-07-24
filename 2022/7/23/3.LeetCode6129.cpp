/*************************************************************************
	> File Name: 3.LeetCode6129.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月23日 星期六 22时38分07秒
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

long long zeroFilledSubarray(vector<int>& nums) {
  int n = nums.size();
  vector<long long> dp(n + 1, 0);
  for (int i = 0; i < n; i++) 
    dp[i + 1] = nums[i] == 0 ? (1 + dp[i]) : 0;
  long long ans = 0;
  for (long long x : dp) ans += x;
  return ans;
}

int main() {
  return 0;
}
