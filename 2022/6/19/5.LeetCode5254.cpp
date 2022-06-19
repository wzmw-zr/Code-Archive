/*************************************************************************
	> File Name: 5.LeetCode5254.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年06月19日 星期日 16时26分45秒
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

long long sellingWood(int m, int n, vector<vector<int>>& prices) {
  long long A[m + 1][n + 1];
  long long dp[m + 1][n + 1];
  memset(A, 0, sizeof(A));
  memset(dp, 0, sizeof(dp));
  for (auto && price : prices) A[price[0]][price[1]] = price[2];
  for (int h = 1; h <= m; h++) {
    for (int w = 1; w <= n; w++) {
      dp[h][w] = A[h][w];
      for (int x = 1; x <= h - 1; x++) dp[h][w] = max(dp[h][w], dp[x][w] + dp[h - x][w]);
      for (int x = 1; x <= w - 1; x++) dp[h][w] = max(dp[h][w], dp[h][x] + dp[h][w - x]);
    }
  }
  return dp[m][n];
}

int main() {
  return 0;
}
