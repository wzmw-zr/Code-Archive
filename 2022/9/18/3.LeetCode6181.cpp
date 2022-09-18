/*************************************************************************
	> File Name: 3.LeetCode6181.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年09月18日 星期日 10时31分52秒
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

int longestContinuousSubstring(string s) {
  int n = s.size();
  int ans = 1;
  vector<int> dp(n, 1);
  for (int i = 1; i < n; i++) {
    if ((s[i] - s[i - 1]) == 1)
      dp[i] = dp[i - 1] + 1;
    ans = max(ans, dp[i]);
  }
  return ans;
}

int main() {
  return 0;
}
