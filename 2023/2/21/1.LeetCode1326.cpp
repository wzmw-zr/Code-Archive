/*************************************************************************
	> File Name: 1.LeetCode1326.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年02月21日 星期二 09时41分38秒
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
int minTaps(int n, vector<int>& ranges) {
  vector<vector<int>> intervals;
  for (int i = 0; i <= n; i++) {
    int left = max(0, i - ranges[i]);
    int right = min(n, i + ranges[i]);
    intervals.push_back({left, right, ranges[i]});
  }
  sort(intervals.begin(), intervals.end(), [&](vector<int> &x, vector<int> &y){
    return x[1] == y[1] ? x[0] < y[0] : x[1] < y[1];
  });
  int dp[n + 200];
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 0; i <= n; i++) {
    int left = intervals[i][0], right = intervals[i][1], range = intervals[i][2];
    if (!range)
      continue;
    for (int x = left + 1; x <= right + 1; x++) 
      dp[x] = min(dp[x], dp[left] + 1);
  }
  return dp[n + 1] == 0x3f3f3f3f ? -1 : dp[n + 1];
}

int main() {
  return 0;
}
