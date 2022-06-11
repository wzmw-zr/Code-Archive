/*************************************************************************
> File Name: 1.LeetCode926.cpp
> Author: 
> Mail: 
> Created Time: 2022年06月11日 星期六 08时40分25秒
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

int minFlipsMonoIncr(string s) {
  int n = s.size();
  int dp[n][2];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = s[0] == '0' ? 0 : 1;
  dp[0][1] = s[0] == '1' ? 0 : 1;
  for (int i = 1; i < n; i++) {
    if (s[i] == '0') {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
    } else {
      dp[i][0] = dp[i - 1][0] + 1;
      dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]);
    }
  }
  for (int i = 0; i < n; i++) cout << dp[i][0] << " ";
  cout << endl;
  for (int i = 0; i < n; i++) cout << dp[i][1] << " ";
  cout << endl;
  return min(dp[n - 1][0], dp[n - 1][1]);
}

int main() {
  string s;
  cin >> s;
  cout << minFlipsMonoIncr(s) << endl;
  return 0;
}
