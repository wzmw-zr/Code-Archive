/*************************************************************************
	> File Name: 2.LeetCode887.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月16日 星期一 20时09分08秒
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

int dp[10010][110];

int dfs(int k, int n) {
  if (n == 0) return 0;
  if (k == 0) return 0x3f3f3f3f;
  if (dp[n][k] != -1) return dp[n][k];
  int mmin = INT32_MAX;
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    int left = dfs(k - 1, mid - 1);
    int right = dfs(k, n - mid);
    if (right >= left) l = mid;
    else r = mid - 1;
  }
  int t = max(dfs(k - 1, l - 1), dfs(k, n - l)) + 1;
  if (l != n) 
    t = min(t, max(dfs(k - 1, l), dfs(k, n - l - 1)) + 1);
  return dp[n][k] = t;
}

int superEggDrop(int k, int n) {
  memset(dp, 0xff, sizeof(dp));
  return dfs(k, n);
}

int main() {
  return 0;
}
