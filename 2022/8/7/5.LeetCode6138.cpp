/*************************************************************************
	> File Name: 5.LeetCode6138.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年08月07日 星期日 10时55分51秒
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

int longestIdealString(string s, int k) {
  unordered_map<char, vector<char>> mp;
  for (char c = 'a'; c <= 'z'; c++) {
    mp[c] = vector<char>(0);
    for (char x = 'a'; x <= 'z'; x++) {
      if (abs(int(c - x)) <= k) 
        mp[c].push_back(x);
    }
  }
  unordered_map<char, int> dp;
  for (char c = 'a'; c <= 'z'; c++) dp[c] = 0;
  for (char c : s) {
    int mmax = 0;
    for (char x : mp[c])
      mmax = max(mmax, dp[x]);
    dp[c] = mmax + 1;
  }
  int ans = 0;
  for (auto && [c, len] : dp) 
    ans = max(ans, len);
  return ans;
}

int main() {
  return 0;
}
