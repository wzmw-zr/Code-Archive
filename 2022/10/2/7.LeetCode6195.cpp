/*************************************************************************
	> File Name: 7.LeetCode6195.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年10月02日 星期日 21时26分18秒
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

int deleteString(string s) {
  int n = s.size();
  int pre[n + 1][n + 1];
  memset(pre, 0, sizeof(pre));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      if (s[i] == s[j])
        pre[i][j] = pre[i + 1][j + 1] + 1;
    }
  }
  int dp[n + 1];
  for (int i = 0; i < n; i++)
    dp[i] = 1;
  for (int i = n - 2; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      if (pre[i][j] >= (j - i))
        dp[i] = max(dp[i], dp[j] + 1);
    }
  }
  return dp[0];
}

int main() {
  return 0;
}
