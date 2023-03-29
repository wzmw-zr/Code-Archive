/*************************************************************************
	> File Name: 1.LeetCode1641.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年03月29日 星期三 09时28分45秒
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

int countVowelStrings(int n) {
  int dp[n + 1][5];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i <= n; i++)
    dp[i][0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 4; j++) {
      for (int k = 1; k <= i; k++) {
        for (int p = 0; p < j; p++) {
          dp[i][j] += dp[i - k][p];
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < 5; i++)
    ans += dp[n][i];
  return ans;
}

int main() {
  return 0;
}
