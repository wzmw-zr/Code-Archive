/*************************************************************************
	> File Name: 3.LeetCode6328.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年04月01日 星期六 22时36分17秒
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

int maximumCostSubstring(string s, string chars, vector<int>& vals) {
  int n = s.size();
  int m = chars.size();
  unordered_map<char, int> mp;
  for (int i = 0; i < 26; i++)
    mp['a' + i] = i + 1;
  for (int i = 0; i < m; i++)
    mp[chars[i]] = vals[i];
  vector<int> dp(n + 1, 0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    dp[i + 1] = max(mp[s[i]], mp[s[i]] + dp[i]);
    ans = max(ans, dp[i + 1]);
  }
  return ans;
}

int main() {
  return 0;
}
