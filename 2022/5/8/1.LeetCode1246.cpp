/*************************************************************************
	> File Name: 1.LeetCode1246.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月08日 星期日 09时25分10秒
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

int minimumMoves(vector<int>& arr) {
  int n = arr.size();
  int dp[n][n];
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 0; i < n; i++) dp[i][i] = 1;
  for (int l = 2; l <= n; l++) {
    for (int i = 0; i + l - 1 < n; i++) {
      if (arr[i] == arr[i + l - 1]) {
        if (dp[i + 1][i + l - 2] == 0x3f3f3f3f) dp[i][i + l - 1] = 1;
        else dp[i][i + l - 1] = dp[i + 1][i + l - 2];
      }
      for (int j = i; j < i + l - 1; j++) 
        dp[i][i + l - 1] = min(dp[i][i + l - 1], dp[i][j] + dp[j + 1][i + l - 1]);
    }
  }
  return dp[0][n - 1];
}

int main() {
  return 0;
}
