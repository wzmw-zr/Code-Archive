/*************************************************************************
	> File Name: 1.LeetCode1824.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年01月21日 星期六 01时35分42秒
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

int minSideJumps(vector<int>& obstacles) {
  int n = obstacles.size();
  int dp[n + 1][3];
  memset(dp, 0x3f, sizeof(dp));
  dp[0][1] = 0;
  dp[0][0] = dp[0][2] = 1;
  for (int i = 1; i < n; i++) {
    if (obstacles[i] == 0) {
      int mmin = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
      dp[i][0] = min(dp[i - 1][0], mmin + 1);
      dp[i][1] = min(dp[i - 1][1], mmin + 1);
      dp[i][2] = min(dp[i - 1][2], mmin + 1);
    } else {
      int plane = obstacles[i];
      int mmin = INT32_MAX;
      for (int j = 1; j <= 3; j++)
        if (plane != j)
          mmin = min(mmin, dp[i - 1][j - 1]);
      for (int j = 1; j <= 3; j++)
        if (plane != j)
          dp[i][j - 1] = min(dp[i - 1][j - 1], mmin + 1);
    }
  }
  for (int i = 0; i < n; i++)
    cout << dp[i][0] << ", " << dp[i][1] << ", " << dp[i][2] << endl;
  return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}

int main() {
  return 0;
}
