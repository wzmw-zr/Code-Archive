/*************************************************************************
	> File Name: 1.LeetCode1388.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年08月18日 星期五 14时01分13秒
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

int calculate(vector<int> &vals, int n) {
  int m = vals.size();
  int dp[m + 1][n + 1][2];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= min(i, n); j++) {
      dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
      dp[i][j][1] = dp[i - 1][j - 1][0] + vals[i - 1];
    }
  }
  int ans = 0;
  for (int i = 0; i <= m; i++)
    ans = max({ans, dp[i][n][0], dp[i][n][1]});
  return ans;
}

int maxSizeSlices(vector<int>& slices) {
  int m = slices.size(), n = m / 3;
  vector<int> vals1(slices.begin(), prev(slices.end()));
  vector<int> vals2(next(slices.begin()), slices.end());
  return max(calculate(vals1, n), calculate(vals2, n));
}

int main() {
  return 0;
}
