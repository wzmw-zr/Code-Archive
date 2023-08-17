/*************************************************************************
	> File Name: 1.LeetCode1444.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月17日 星期四 08时42分41秒
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
#include <functional>
#include <cstring>
#include <cstdlib>
using namespace std;

long MOD = 1e9 + 7;

int ways(vector<string>& pizza, int k) {
  int m = pizza.size(), n = pizza[0].size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + (pizza[i][j] == 'A' ? 1 : 0);
    }
  }
  int check[51][51][11];
  int val[51][51][11];
  memset(check, 0, sizeof(check));
  memset(val, 0, sizeof(val));
  function<long(int, int, int)> dfs = [&](int x, int y, int rest) -> long {
    if (rest == 1) {
      return (dp[m][n] - dp[m][y] - dp[x][n] + dp[x][y] >= 1) ? 1 : 0;
    }
    if (check[x][y][rest])
      return val[x][y][rest];
    int cnt = dp[m][n] - dp[m][y] - dp[x][n] + dp[x][y];
    long ans = 0;
    for (int i = x; i < m - 1; i++) {
      int cnt_1 = dp[i + 1][n] - dp[x][n] - dp[i + 1][y] + dp[x][y];
      if (cnt_1 > 0 && cnt_1 < cnt) {
        ans = (ans + dfs(i + 1, y, rest - 1)) % MOD;
      }
    }
    for (int i = y; i < n - 1; i++) {
      int cnt_1 = (dp[m][i + 1] - dp[m][y] - dp[x][i + 1] + dp[x][y]);
      if (cnt_1 > 0 && cnt_1 < cnt) {
        ans = (ans + dfs(x, i + 1, rest - 1)) % MOD;
      }
    }
    check[x][y][rest] = 1;
    return val[x][y][rest] = ans;
  };
  return dfs(0, 0, k);
}

int main() {
  return 0;
}
