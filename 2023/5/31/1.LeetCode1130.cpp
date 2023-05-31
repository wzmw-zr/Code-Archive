/*************************************************************************
	> File Name: 1.LeetCode1130.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月31日 星期三 09时39分38秒
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
using namespace std;

int mctFromLeafValues(vector<int>& arr) {
  int n = arr.size();
  vector<vector<int>> mmin(n, vector<int>(n, INT32_MAX));
  for (int i = 0; i < n; i++) {
    mmin[i][i] = arr[i];
    for (int j = i + 1; j < n; j++)
      mmin[i][j] = max(mmin[i][j - 1], arr[j]);
  }
  vector<vector<int>> dp(n, vector<int>(n, INT32_MAX));
  function<int(int, int)> dfs = [&](int left, int right) -> int {
    if (left == right)
      return dp[left][right] = 0;
    if (dp[left][right] != INT32_MAX)
      return dp[left][right];
    for (int i = left; i < right; i++) {
      int val = dfs(left, i) + dfs(i + 1, right) + mmin[left][i] * mmin[i + 1][right];
      dp[left][right] = min(dp[left][right], val);
    }
    return dp[left][right];
  };
  return dfs(0, n - 1);
}

int main() {
  return 0;
}
