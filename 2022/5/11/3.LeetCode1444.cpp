/*************************************************************************
	> File Name: 3.LeetCode1444.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月11日 星期三 16时31分43秒
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

// WA
int m, n;
long MOD = 1e9 + 7;
long dp[55][55][15];
int pre[55][55];

long dfs(int x, int y, int k) {
  if (x >= m || y >= n) {
    if (k == 0) return 1;
    return 0;
  }
  if (dp[x][y][k] != -1) return dp[x][y][k];
  int rest = pre[m + 1][n + 1] - pre[m + 1][y] - pre[x][n + 1] + pre[x][y];
  if (rest < k) return dp[x][y][k] = 0;

  long ans = 0;
  for (int i = x; i < m; i++) {
    int cnt = pre[i + 1][n + 1] - pre[i + 1][y] - pre[x][n + 1] + pre[x][y];
    if (cnt > 0) 
      ans = (ans + dfs(i + 1, y, k - 1)) % MOD;
  }

  for (int i = y; i < n; i++) {
    int cnt = pre[m + 1][i + 1] - pre[m + 1][y] - pre[x][i + 1] + pre[x][y];
    if (cnt > 0) 
      ans = (ans + dfs(x, i + 1, k - 1)) % MOD;
  }
  return dp[x][y][k] = ans;
}

int ways(vector<string>& pizza, int k) {
  memset(dp, 0xff, sizeof(dp));
  memset(pre, 0, sizeof(pre));
  m = pizza.size();
  n = pizza[0].size();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + (pizza[i][j] == 'A' ? 1 : 0);
    }
  }
  return dfs(0, 0, k);
}

int main() {
  return 0;
}
