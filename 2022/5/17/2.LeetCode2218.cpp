/*************************************************************************
	> File Name: 2.LeetCode2218.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年05月17日 星期二 19时15分04秒
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

int maxValueOfCoins(vector<vector<int>>& piles, int k) {
  int n = piles.size();
  vector<vector<int>> pre;
  for (int i = 0; i < n; i++) {
    vector<int> temp(1, 0);
    for (int j = 0; j < piles[i].size(); j++) temp.push_back(*temp.rbegin() + piles[i][j]);
    pre.push_back(temp);
  }
  int dp[n + 1][k + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    int t = piles[i].size();
    for (int l = 1; l <= k; l++) {
      for (int j = 1; j <= min(l, t); j++) {
        dp[i + 1][l] = max({dp[i][l], dp[i + 1][l], dp[i][l - j] + pre[i][j]});
      }
    }
  }
  return dp[n][k];
}

int main() {
  return 0;
}
