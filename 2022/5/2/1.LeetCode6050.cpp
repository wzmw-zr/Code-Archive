/*************************************************************************
	> File Name: 1.LeetCode6050.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月02日 星期一 16时26分23秒
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
#include <cstring>
#include <cstdlib>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

long long appealSum(string s) {
  int n = s.size();
  long long dp[n][26];
  memset(dp, 0, sizeof(dp));
  dp[0][s[0] - 'a'] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 26; j++) dp[i][j] = dp[i - 1][j];
    dp[i][s[i] - 'a'] = i + 1;
  }
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) sum += dp[i][j];
  }
  return sum;
}

int main() {
  return 0;
}
