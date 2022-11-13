/*************************************************************************
	> File Name: 5.LeetCode6236.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年11月13日 星期日 11时00分47秒
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

int maxPalindromes(string s, int k) {
  int n = s.size();
  int dp1[n + 10][n + 10];
  int dp2[n + 10];
  int mmax[n + 10];
  memset(dp1, 0, sizeof(dp1));
  memset(dp2, 0, sizeof(dp2));
  memset(mmax, 0, sizeof(mmax));
  for (int i = 0; i < n; i++) {
    dp1[i][i] = 1;
    mmax[i] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    dp1[i][i + 1] = s[i] == s[i + 1] ? 2 : 0;
    mmax[i + 1] = max(dp1[i][i + 1], mmax[i + 1]);
  }
  for (int len = 3; len <= n; len++) {
    for (int i = 0; i + len - 1 < n; i++) {
      dp1[i][i + len - 1] = s[i] == s[i + len - 1] ? (dp1[i + 1][i + len - 2] ? dp1[i + 1][i + len - 2] + 2 : 0): 0;
      mmax[i + len - 1] = max(dp1[i][i + len - 1], mmax[i + len - 1]);
    }
  }

  for (int i = 1; i <= n; i++) {
    dp2[i] = dp2[i - 1];
    if (mmax[i - 1] >= k) {
      for (int j = 1; j <= i - k + 1; j++) {
        if (dp1[j - 1][i - 1]) {
          dp2[i] = max(dp2[j - 1] + 1, dp2[i]);
        }
      }
    }
  }
  return dp2[n];
}

int main() {
  return 0;
}
