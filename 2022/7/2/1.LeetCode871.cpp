/*************************************************************************
	> File Name: 1.LeetCode871.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月02日 星期六 09时14分37秒
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

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
  if (startFuel >= target) return 0;
  int n = stations.size();
  if (n == 0) return -1;
  if (stations[0][0] > target || stations[0][0] > startFuel) return -1;
  long dp[n + 1][n + 1];
  memset(dp, -1, sizeof(dp));
  dp[0][0] = startFuel;
  int pre = 0;
  int ind = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (dp[i][j] != -1 && dp[i][j] >= (stations[i][0] - pre)) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - (stations[i][0] - pre));
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] - (stations[i][0] - pre) + stations[i][1]);
      }
    }
    pre = stations[i][0];
  }
  for (int i = 0; i < n; i++) {
    if (stations[i][0] < target) ind = i;
    else break;
  }
  int dis = target - stations[ind][0];
  for (int i = 0; i <= ind + 1; i++) {
    if (dp[ind + 1][i] >= dis) return i;
  }
  return -1;
}

int main() {
  return 0;
}
