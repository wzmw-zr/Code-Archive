/*************************************************************************
	> File Name: 1.LeetCode1278.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年03月31日 星期四 00时04分34秒
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

int palindromePartition(string s, int k) {
  int n = s.size();
  int dp[n + 1][n + 1][k + 1];
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int x = i, y = j;
      int cnt = 0;
      while (x < y) {
        if (s[x] != s[y]) cnt++;
        x++, y--;
      }
      dp[i][j][1] = cnt;
    }
  }
  for (int i = 2; i <= k; i++) {
    for (int j = 0; j + i - 1 < n; j++) {
      for (int p = j + i - 1; p < n; p++) {
        for (int m = j + i - 2; m < n - 1; m++) {
          dp[j][p][i] = min(dp[j][p][i], dp[j][m][i - 1] + dp[m + 1][p][1]);
        }
      }
    }
  }
  return dp[0][n - 1][k];
}

int main() {
  string s;
  int k;
  cin >> s >> k;
  cout << palindromePartition(s, k) << endl;
  return 0;
}
